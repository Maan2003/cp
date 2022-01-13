fn solve() {
    input! {
        n: u,
        a: [i; n],
    }

    if n == 1 {
        ans!(0);
    }

    let mut ans = n;
    let D = |i: u, j: u| {
        if i < j {
            (a[j] - a[i]) as f64 / (j - i) as f64
        } else {
            (a[i] - a[j]) as f64 / (i - j) as f64
        }
    };
    for i in 0..n {
        for j in 0..n {
            if i == j {
                continue;
            }
            let d = D(i, j);
            let mut cnt = 0;
            for k in 0..n {
                if k == i || k == j {
                    continue;
                }

                if (d - D(i, k)).abs() > 1e-6 {
                    cnt += 1;
                }
            }
            if cnt < ans {
                ans = cnt;
            }
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
