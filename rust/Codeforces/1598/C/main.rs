cp! {
input {
    n: u,
    a: [i; n],
}

solve {
    let sum = a.iter().sum::<i>();
    for i in 0..n {
        a[i] *= n as i;
    }
    let mut hm = m::<i, (u, u)>::new();
    let mut eq = 0;
    for i in 0..n {
        if a[i] < sum {
            hm.entry(sum - a[i]).or_insert((0, 0)).0 += 1;
        } else if a[i] == sum {
            eq += 1;
        } else {
            hm.entry(a[i] - sum).or_insert((0, 0)).1 += 1;
        }
    }

    let mut ans = 0;
    for (_, (x, y)) in hm {
        ans += x * y;
    }
    if eq != 0 {
        ans += (eq * (eq - 1)) / 2;
    }
    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
