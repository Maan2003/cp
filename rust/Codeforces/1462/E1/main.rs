cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    a.sort_unstable();
    a.push(u::MAX);
    let mut ans: u = 0;
    let mut j = 0;
    for i in 0..n {
        j = j.max(i + 2);
        while j <= n {
            if a[j] - a[i] > 2 {
                let d = j - i - 1;
                ans += d * (d - 1) / 2;
                break;
            }
            j += 1;
        }
    }

    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
