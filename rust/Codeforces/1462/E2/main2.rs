cp! {
input {
    n: u,
    m: i,
    k: u,
    a: [u; n],
}

solve {
    type M = algo::math::num::Modulo<1_000_000_000>;
    a.sort_unstable();
    a.push(u::MAX);
    let mut ans = M::from(0);
    let mut j = 0;
    for i in 0..n {
        j = j.max(i + (m as u) - 1);
        while j <= n {
            if a[j] - a[i] > k {
                let mut d = M::from((j - i - 1) as i);
                // d choose (m - 1)
                let mut val = M::from(1);
                for _ in 0..m - 2 {
                    val = val * d;
                    d = d - M::from(1);
                }
                for x in 2..=m - 1 {
                    val = val / M::from(x);
                }

                ans = ans + val;
                break;
            }
            j += 1;
        }
    }

    ans!(ans.val);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
