fn solve() {
    input! {
        a: [u; 3],
    }

    a.sort();
    if a[0] == a[1] {
        ans!(yn(a[2] % 2 == 0));
    } else if a[1] == a[2] {
        ans!(yn(a[0] % 2 == 0));
    } else {
        ans!(yn(a[0] + a[1] == a[2]));
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
