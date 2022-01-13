fn solve() {
    input! {
        n: u,
        a: [u; n],
    }

    let mut freq = HashMap::<u, u>::new();
    let mut max = 0;
    for i in 0..n {
        let val = freq.entry(a[i]).or_insert(0);
        *val += 1;
        max = (*val).max(max);
    }

    if max > n - max {
        ans!(max - (n - max));
    } else {
        ans!(if n % 2 == 0 { 0 } else { 1 });
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
