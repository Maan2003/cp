cp! {
input {
    n: u,
    s: b,
}

solve {
    let mut sl: i = 0;
    let mut sr: i = 0;
    let mut cl: i = 0;
    let mut cr: i = 0;

    {
    let mut d = 0;
    for i in 0..n {
        if s[i] == b'.' {
            d += 1;
        } else {
            sr += 1;
            cr += d;
        }
    }
    }

    let mut ans = cl + cr;
    for i in 0..n {
        if s[i] == b'.' {
            cl += sl;
            cr -= sr;
        } else {
            // sheep
            sl += 1;
            sr -= 1;
            ans = min(ans, cl + cr);
        }
    }
    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
