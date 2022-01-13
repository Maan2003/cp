cp! {
input {
    n: u,
    a: [u; n],
}

solve {
   let ones = a.iter().filter(|&&x| x == 1).count();
   let twos = a.iter().filter(|&&x| x == 2).count();
   if ones % 2 != 0 {
       ans!(NO);
    }
    if twos % 2 != 0 && ones < 2 {
        ans!(NO);
    }
    ans!(YES);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
