cp! {
input {
    w: u, h: u, n: u,
}

solve {
    let mut cnt = 1;
    while w % 2 == 0 {
        cnt *= 2;
        w /= 2;
    }

    while h % 2 == 0 {
        cnt *= 2;
        h /= 2;
    }
    ans!(yn(cnt >= n));
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
