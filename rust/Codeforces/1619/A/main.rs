fn solve() {
    input! {
        s: b,
    }

    if s[0..s.len() / 2] == s[s.len() / 2..] {
        ans!(YES);
    } else {
        ans!(NO);
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
