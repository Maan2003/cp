cp! {
input {
    n: u,
    a: b,
    b: b,
}

solve {
    for i in 0..n {
        if a[i] == b[i] && a[i] == b'1' {
            ans!(NO);
        }
    }
    ans!(YES);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
