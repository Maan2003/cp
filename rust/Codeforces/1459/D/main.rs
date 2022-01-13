cp! {
kind = single;
input {
    n: u,
    a: [(u, u); n],
}

solve {
    let mut m: HashMapWithDefault<(i, i), i> = m::new().default(0);

    /*
    fn solve(a: &[(u, u)], tw: u, c: &mut m<(u, u, u, u), f64>, i: u, w: u, cap: u, k: u) -> f64 {
        // end of days
        if k == 0 || i == a.len() {
            return w as f64 + (cap as f64).min((tw - w)  as f64 / 2.);
        }

        if let Some(v) = c.get(&(i, w, cap, k)) {
            return *v;
        }

        // if we select this
        let x = {
            let ccap = a[i].0 - a[i].1;
            solve(a, tw, c, i + 1, w + a[i].1, cap + ccap, k - 1)
        };

        let y = solve(a, tw, c, i + 1, w, cap, k);
        let val = f64::max(x, y);
        c.insert((i, w, cap, k), val);
        val
    }

    let mut c = m::new();

    let total_w = a.iter().map(|&(_, w)| w).sum::<u>();
    for k in 1..=n {
        let val = solve(&a, total_w, &mut c, 0, 0, 0, k);
        print!("{:.10} ", val);
    }
    */
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
