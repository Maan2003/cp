fn solve() {
    input! {
        x: u,
    }
    for a in 1.. {
        let a3 = a * a * a;
        if a3 > x {
            break;
        }
        let b3 = x - a3;
        let b = (b3 as f64).cbrt().round() as u;
        if b >= 1 && a3 + b * b * b == x{
            ans!(YES);
        }
    }
    ans!(NO);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
