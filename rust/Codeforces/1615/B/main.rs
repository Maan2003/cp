fn solve() {
    input! {
        l: u, r: u,
    }

    let mut a: [u; 32] = [0; 32];
    let mut x = 1;
    for b in 0..32 {
        a[b] = (((x << 1) - 1).min(r) as i - (x).max(l) as i + 1i64).max(0) as u;
        x <<= 1;
    }

    let val = *a.iter().max().unwrap_or(&0);
    let cnt = r - l + 1;
    ans!(cnt - val);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
