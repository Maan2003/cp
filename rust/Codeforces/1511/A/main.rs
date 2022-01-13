fn solve() {
    input! {
        n: u,
        a: [u; n],
    }

    ans!(a.into_iter().filter(|x| *x == 1 || *x == 3).count());
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
