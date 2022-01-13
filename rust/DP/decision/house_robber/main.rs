#![allow(unused_parens)]
cp! {
kind = single;
input {
    n: u,
    k: i32,
    a: [i32; n],
}

solve {
    let mut max = vec![0; n];
    max[0] = a[0];
    max[1] = a[1];
    for i in 2..n {
        max[i] = max[i - 1].max(a[i] + max[i - 2]);
    }
    ans!(max[n - 1]);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
