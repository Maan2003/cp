fn solve() {
    input! {
        n: i, k: i,
        a: [i; n],
    }

    a.sort_unstable();
    let mut sum = a.iter().sum::<i>();

    let mut ans: u = 0;
    let mut i = 1;

    loop {
        if sum <= k {
            ans!(ans);
        }
        // the set this value helps more than reducing the value of min
        if i < n && a[(n - i).u()] - a[0] >= i {
            sum -= a[(n - i).u()] - a[0];
            i += 1;
            ans += 1;
        } else {
            let mut cnt = ((sum - k) as f64 / i as f64).ceil() as i;
            if i < n {
                cnt = cnt.min(i - a[(n - i).u()] + a[0]);
            }
            a[0] -= cnt;
            // lets reduce the value of min
            sum -= i * cnt;
            ans += cnt as u;
        }
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
