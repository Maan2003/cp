cp! {
kind = multi;
input {
    n: u,
    a: [(u, u, u); n],
}

rand {
    n = r(1..10);
    a = {
        let l = r(1..10);
        (l, l + r(0..10), r(1..10))
    };
}

naive {
    for s in 1..=n {
        let mut v = vuu::new();
        for i in 0..s {
            for j in 0..s {
                v.push((
                    max(a[i].1, a[j].1) - min(a[i].0, a[j].0),
                    if i == j { a[i].2 } else { a[i].2 + a[j].2 },
                ));
            }
        }
        v.sort_by_key(|&(a, b)| (-(a as i), b));
        outln!(v[0].1);
    }
}

solve {
    let mut min = u::MAX;
    let mut max = u::MIN;
    let mut cost = u::MAX;
    let mut c1 = u::MAX;
    let mut c1_min = u::MAX;
    let mut c2 = u::MAX;
    let mut c2_min = u::MAX;
    for (l, r, c) in &a {
        match ((*l).cmp(&min), (*r).cmp(&max)) {
            (Ordering::Equal, Ordering::Equal) => {
                if *c < cost {
                    cost = *c;
                    c1 = *l;
                    c2 = *r;
                }
            }
            (Ordering::Less | Ordering::Equal, Ordering::Greater | Ordering::Equal) => {
                cost = *c;
                c1 = *c;
                c2 = *c;
            }
            (Ordering::Less, _) => {
                c1 = *c;
                cost = c1 + c2_min;
            }
            (_, Ordering::Greater) => {
                c2 = *c;
                cost = c1_min + c2;
            }
            (Ordering::Equal, _) => {
                if *c + c2_min < cost {
                    cost = *c + c2_min;
                    c1 = *c;
                }
            }
            (_, Ordering::Equal) => {
                if *c + c1_min < cost {
                    cost = *c + c1_min;
                    c2 = *c;
                }
            }
            (Ordering::Greater, Ordering::Less) => {}
        }
        if *l < min {
            c1_min = *c;
        }
        if *l == min {
            c1_min = c1_min.min(*c);
        }
        if *r > max {
            c2_min = *c;
        }
        if *r == max {
            c2_min = c2_min.min(*c);
        }
        output!(cost;);
        min = min.min(*l);
        max = max.max(*r);
    }
}


}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
