fn solve() {
    input! {
        n: u,
        p: [u; n],
        r: b,
    }

    let mut idx: Vec<u> = (0..n).collect();
    idx.sort_by_key(|&i| (r[i] - b'0', p[i]));
    for i in 1..=n {
        p[idx[i - 1]] = i;
    }
    ans!(p,*);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
