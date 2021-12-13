fn read<T>() -> T {
    todo!()
}

macro_rules! stmt! {
    (read $var:ident
     $($tok:tt)*) => {
        let $var = read();
        stmt!($($tok)*)
     );

     (read_ty $var:ident : <$t:ty>
      $($tok:tt)*) => {
        let $var: $t = read();
        stmt!($($tok)*)
     };

     (print ($expr:expr) $($tok:tt)*) => {
        println!("{}", $expr);
        stmt!($($tok)*)
     };

     (print $fn:ident($($input:tt)*) $($tok:tt)*) => {
        println!("{}", $fn ($($input)*));
        stmt!($($tok)*)
     };

     (tests $($tok:tt)*) => {
        let tests = read::<usize>();
        for _ in 0..tests {
            stmt!($($tok)*)
        }
     };
}
macro_rules! main {
    ($($tt:tt)*) => {
        fn main() {
            stmt! {
                $($tt:tt)*
            }
        }
    }
}

main! {
    tests
    read n
    read y
    
}
