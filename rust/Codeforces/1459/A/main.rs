cp! {
input {
    n,
    a: b,
    b: b,
}

solve {
    let mut r: u = 0;
    let mut bl: u = 0;
    for i in 0..n {
        if a[i] > b[i] {
            r += 1;
        } else if a[i] < b[i] {
            bl += 1;
        }
    }
    let ans = if r > bl {
        "RED"
    } else if r < bl {
        "BLUE"
    } else {
        "EQUAL"
    };
    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
