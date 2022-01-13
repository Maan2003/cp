fn solve() {
    input! {
        n: u,
        a: [u; n],
    }

    let mut sum = a.iter().sum::<u>();
    let mut v: v<_> = a.iter().copied().enumerate().map(|(x, y)| (y, x)).collect();
    v.sort();
    let mut ans = 0;
    for (i, (x, _)) in v.iter().enumerate().rev() {
        sum -= x;
        if sum < *x {
            ans = i;
            break;
        }
    }
    let mut ans: vu = v[ans..].iter().map(|(_, idx)| *idx + 1).collect();
    ans.sort();
    ans!(ans.len(); ans,*);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
