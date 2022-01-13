cp! {
kind = single;
input {
    n: u,
}

solve {
    let n2 = n * n;
    let mut a = vec![vec![]; n];
    let mut offset = 0;
    for i in 1..=n2 {
        let x = (i + offset - 1) % n;
        a[x].push(i);
        if i % n == 0 {
            offset += 1;
        }
    }
    for values in a {
        output!(values,*);
        println!();
    }
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
