fn bflr(f: f64) -> i32 {
    let fl = f.floor();
    let rd = f.round();
    if rd - f > 1e-9 {
        fl as i32
    } else {
        rd as i32
    }
}

fn solve() {
    input! { n: i32 }
    let sqs = bflr((n as f64).sqrt());
    let cbs = bflr((n as f64).cbrt());
    let both = bflr((n as f64).powf(1.0 / 6.0));
    ans! { sqs + cbs - both; }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
