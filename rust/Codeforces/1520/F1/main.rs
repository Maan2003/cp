cp! {
    input {
        n: u,
        _t: u,
        k: u,
    }

    solve {
        let q = |l: u, r: u| -> u {
            println!("? {} {}", l + 1, r);
            flush!();
            input!(x: u);
            x
        };

        let mut l: u = 0;
        let mut r: u = n;
        while l < r - 1 {
            let m = (l + r) / 2;
            let v = m - q(0, m);
            if v < k {
                l = m;
            } else {
                r = m;
            }
        }
        println!("! {}", l + 1);
        flush!();
    }
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;
#[cfg(not(ONLINE_JUDGE))]
use cp::*;
