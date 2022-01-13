cp! {
input {
    n: u,
    m: i,
    k: u,
    a: [u; n],
}

pre {
    type M = algo::math::num::Modulo<1_000_000_000>;
}

solve {
    a.sort_unstable();
    a.push(u::MAX);
    let mut ans = M::from(0);
    let mut j = 0;
    for i in 0..n {
        j = j.max(i + (m as u) - 1);
        while j <= n {
            if a[j] - a[i] > k {
                fn choose(n: i, k: i) -> M {
                    let mut ans = 1.0;
                    if n == k {
                        return M::from(1);
                    }
                    let n = n as f64;
                    for i in 0..k {
                        ans = ans * (n - i as f64);
                    }
                    for i in 1..k + 1 {
                        ans = ans / i as f64;
                    }
                    // better round
                    M::from(ans.round() as i)
                }

                let d = (j - i - 1) as i;
                // d choose (m - 1)
                ans = ans + choose(d, m - 1);
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
