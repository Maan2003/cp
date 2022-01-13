fn solve() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let f = a[0];
    let s = a[1];
    if s == f {
        for (i, e) in a.iter().enumerate() {
            if e != &f {
                ans!(i + 1);
            }
        }
    } else if a[2] == f {
        ans!(2);
    } else {
        ans!(1);
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
