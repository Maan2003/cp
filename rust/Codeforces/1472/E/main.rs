cp! {
input {
    n: u,
    a: [(u, u); n],
}

solve {
    let mut b = vec![];
    for i in 0..n {
        let (x, y) = a[i];
        b.push((x, y, i));
        b.push((y, x, i));
    }

    b.sort_unstable();
    let mut ans = vec![-1i64; n];
    let mut min_2 = u::MAX;
    let mut min_2_idx = -1i64;
    let mut mins = vec![u::MAX; n * 2];
    let mut i = 0;
    while i < b.len(){
        let (x, _, _) = b[i];
        let mut min_val = min_2;
        let mut min_idx = min_2_idx;
        while i < b.len() && b[i].0 == x {
            if (b[i].1) < min_val {
                min_val = b[i].1;
                min_idx = b[i].2 as i;
            }
            min_val = min(min_val, b[i].1);
            // we found a fitting block
            if min_2 < b[i].1 {
                ans[b[i].2] = min_2_idx;
            }
            mins[i] = min_2;
            i += 1
        }
        min_2_idx = min_idx;
        min_2 = min_val;
    }

    for x in ans {
        if x == -1 {
            print!("-1 ");
        } else {
            print!("{} ", x + 1);
        }
    }
    println!();
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
