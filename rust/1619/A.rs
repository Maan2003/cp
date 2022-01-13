fn solve() {
    input! { s: b }
    if s.len() % 2 == 1 {
        ans!(NO);
    }
    for i in 0..s.len() / 2 {
        if s[i] != s[s.len() / 2 + i] {
            ans!(NO);
        }
    }
    ans!(YES);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
