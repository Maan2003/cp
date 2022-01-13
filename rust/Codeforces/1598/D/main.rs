cp! {
input {
    n: u,
    a: [(u, u); n],
}

solve {
    let mut t = m::<u, u>::new();
    let mut d = m::<u, u>::new();
    for &(x, y) in &a {
        *t.entry(x).or_insert(0) += 1;
        *d.entry(y).or_insert(0) += 1;
    }

    let mut ans = n * (n - 1) * (n - 2) / 6;
    for (x, y) in a {
        ans -= (t[&x] - 1) * (d[&y] - 1);
    }

    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
