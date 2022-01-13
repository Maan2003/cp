cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    a.sort();
    let mut ans = 0;
    for r in (0..a.len()).rev() {
        let diff = a[a.len() - 1] - a[r];
        for l in 0..=r {
            a[l] += diff;
        }
        ans += diff;
    }
    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
