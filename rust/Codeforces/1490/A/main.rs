fn solve() {
    input! {
        n: u,
        a: [u; n],
    }

    let mut ans: u = 0;
    for i in 0..n - 1 {
        let mut l = a[i].min(a[i + 1]);
        let r = a[i + 1].max(a[i]);
        while l * 2 < r {
            l *= 2;
            ans += 1;
        }
    }
    ans!(ans);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
