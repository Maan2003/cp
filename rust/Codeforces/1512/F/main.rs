const INF: i64 = 1 << 60;
fn solve() {
    input! {
        n: u, c: i,
        a: [i; n],
        b: [i; n - 1],
    }

    let mut ans = INF;
    let mut money: i = 0;
    let mut day: i = 0;
    for i in 0..n {
        // try to gather enough to buy laptop
        let days = day + ((c - money) as f64 / a[i] as f64).ceil() as i;
        if days < ans {
            ans = days;
        }

        let prom = if i != n - 1 { b[i] } else { INF };
        let days = ((prom as f64 - money as f64) / a[i] as f64).ceil() as i;
        money = days * a[i] - (prom - money);
        // one day to promote
        day += 1 + days;
    }
    ans!(ans);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
