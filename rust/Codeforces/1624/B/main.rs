cp! {
input {
    a: i,
    b: i,
    c: i,
}

solve {
    // only change
    let b22 = a + c;
    if b22 % (2 * b) == 0 && b22 / (2 * b) > 0 {
        ans!(YES);
    }

    let a2 = 2 * b - c;
    if a2 % a == 0 && a2 / a > 0 {
        ans!(YES);
    }

    let c2 = 2 * b - a;
    if c2 % c == 0 && c2 / c > 0 {
        ans!(YES);
    }

    ans!(NO);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
