fn solve() {
    input! {
        n: u,
        a: [i; n],
    }

    let mut m = m::new();
    for x in &a {
        *m.entry(x.abs()).or_insert(0) += 1usize;
    }

    let mut cnt: u = 0;
    for (x, f) in m {
        if x == 0 {
            cnt += 1;
        } else {
            cnt += f.min(2);
        }
    }
    ans!(cnt);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
