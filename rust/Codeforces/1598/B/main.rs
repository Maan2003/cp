cp! {
input {
    n: u,
    a: [[u; 5]; n],
}

solve {
    for i in 0..5 {
        'outer: for j in 0..i {
            let mut c1: i = 0;
            let mut c2: i = 0;
            let mut both: i = 0;
            for k in 0..n {
                if a[k][i] == 1 && a[k][j] == 1 {
                    both += 1;
                } else if a[k][i] == 1 {
                    c1 += 1;
                } else if a[k][j] == 1 {
                    c2 += 1;
                } else {
                    continue 'outer;
                }
            }
            if (c1 - c2).abs() > both {
                continue 'outer;
            }
            ans!(YES);
        }
    }
    ans!(NO);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
