cp! {
kind = single;
input {
    n: u,
    a: [i; n],
}

solve {
    a.sort_unstable();
    let mut c: i = 1;
    let mut new_cost = i::MAX;
    'outer: loop {
        let mut x = 1;
        let mut cost = 0;
        for i in 0..n {
            cost += (x - a[i]).abs();
            x *= c;
            if x > 1_000_000_000_000_000 {
                break 'outer;
            }
        }
        new_cost = new_cost.min(cost);
        c += 1;
    }
    ans!(new_cost);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
