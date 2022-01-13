cp! {
kind = single;
input {
    n: u,
    a: [u; n],
}

solve {
    let mut hm = m::new();
    let max = *a.iter().max().unwrap();
    for i in 0..n {
        let mut ops: u = 0;
        let mut temp = a[i];
        loop {
            let (cost, count) = hm.entry(temp).or_insert((0usize, 0usize));
            *count += 1;
            *cost += ops;
            ops += 1;
            if temp == 0 {
                break;
            }
            temp /= 2;
        }
        let mut ops: u = 1;
        let mut temp = a[i] * 2;
        while temp <= max {
            let (cost, count) = hm.entry(temp).or_insert((0usize, 0usize));
            *count += 1;
            *cost += ops;
            ops += 1;
            temp *= 2;
        }
    }
    let cost = hm.values().filter(|&&(cost, count)| count == n).map(|(cost, _)| *cost).min().unwrap();
    ans!(cost);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
