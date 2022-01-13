cp! {
kind = single;
input {
    n: u, x: i,
    a: [i; n],
}

solve {
    struct Rt {
        l: i,
        r: i,
        max: i,
        full: i,
    }
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
