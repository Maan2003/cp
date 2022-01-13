fn solve() {
    input! {
        n: u, m: u, x: u,
    }

    x -= 1;
    let i = x / n;
    let j = x % n;

    ans!(j * m + i + 1);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
