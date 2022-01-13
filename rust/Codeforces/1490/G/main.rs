fn solve() {
    input! {
        n: u, m: u,
        a: [i; n],
        q: [i; m],
    }

    let mut s = v::<(u, i)>::new();
    s.push((0, 0));
    let mut sum = 0;
    for (i, &x) in a.iter().enumerate() {
        sum += x;
        if sum > s.last().unwrap().1 {
            s.push((i, sum));
        }
    }
    for x in q {
        if sum > 0 {
            let rounds = x / sum;
            
        } else {
            slice_lower_bound(, key)
        }
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
use cp::algo::order::slice_lower_bound;

