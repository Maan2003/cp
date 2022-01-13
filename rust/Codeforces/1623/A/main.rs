solve! {
(mutli)
input:

code:

output:
    
}
fn solve() {
    input! {
        n: u, m: u,
        r: u, c: u,
        tr: u, tc: u,
    }

    let e1 = {
        if r <= tr {
            tr - r
        } else {
            n - tr + n - r
        }
    };
    let e2 = {
        if c <= tc {
            tc - c
        } else {
            m - tc + m - c
        }
    };
    ans!(e1.min(e2));
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
