cp! {
kind = single;
input {
    n: u, r1: u, r2: u, r3: u, d: u,
    m: [u; n],
}

solve {
    let mut c = v::new();
    for i in 0..n {
        let c1 = (m[i] * r1).min(r2) + r1;
        let c2 = m[i] * r1 + r3;
        c.push((c1, c2));
    }
    if n == 1 {
        ans!(c[0].1);
    }
    if n == 2 {
        let ans =
            [c[0].1 + d + c[1].1,
             c[0].0 + d + c[1].1 + d,
             c[0].0 + d + c[1].0 + d + d,].into_iter().min().unwrap();
        ans!(ans);
    }

    // never come back
    let mut cost = vec![0; n];
    let mut c_cost = 0;
    for i in 0..n {
        let (c1, c2) = c[i];
        if i == n - 1 {
            c_cost += c2;
            cost[i] = c_cost;
            continue;
        }
        c_cost += (c1 + 2 * d).min(c2);
        cost[i] = c_cost;
    }

    // costs if we come back to i
    let mut cost2 = vec![0; n];
    cost2[n - 1] = c[n - 1].1;
    for i in (0..n - 1).rev() {
        let (c1, _) = c[i];
        cost2[i] = c1 + cost2[i + 1];
    }

    // having to come back to the last level
    let mut cost3 = vec![0; n];
    cost3[n - 1] = c[n - 1].0;
    for i in (0..n - 1).rev() {
        let (c1, _) = c[i];
        cost3[i] = c1 + cost3[i + 1];
    }

    let mut ans = u::MAX;
    for i in 1..n {
        let c1 = cost[i - 1] + cost2[i] + d * (n - i - 1) + (n - 1) * d;
        ans = ans.min(c1);
        if i != n - 1 {
            let c2 = cost[i - 1] + cost3[i] + 2 * d * (n - i - 1) + (n - 1) * d;
            ans = ans.min(c2);
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
