cp! {
input {
    n: u,
    a: [(u, u); n],
}

solve {
    let mut segs = vec![];
    for i in 0..n {
        segs.push((true, i));
        segs.push((false, i));
    }

    let val = |x: &(bool, u)| if x.0 { a[x.1].0 } else { a[x.1].1 };
    segs.sort_by(|a, b| {
        // compare by value, then start must be before end
        val(a).cmp(&val(b)).then(a.0.cmp(&b.0).reverse())
    });
    let mut intersections = vec![(0, 0); n];
    let mut intr_id: i = 0;
    let mut current: i = 0;
    for &(is_start, i) in &segs {
        if is_start {
            intersections[i].0 = intr_id - current;
            intr_id += 1;
            current += 1;
        } else {
            intersections[i].1 = intr_id;
            current -= 1;
        }
    }

    let val = intersections.into_iter().map(|x| x.1 - x.0).max().unwrap();
    ans!(n as i - val);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
