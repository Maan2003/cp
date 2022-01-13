cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    let sum = a.iter().sum::<u>();
    let mut cur_sum = 0;
    for i in 0..n {
        cur_sum += a[i];
        if sum % cur_sum != 0 {
            continue;
        }
        // find similar pairs
        let mut seg_sum = 0;
        for j in (i + 1)..n {
            seg_sum += a[j];
            if seg_sum == cur_sum {
                seg_sum = 0;
                continue;
            }
            if seg_sum > cur_sum {
                break;
            }
        }
        if seg_sum == 0 {
            ans!(n - sum / cur_sum);
        }
    }
    ans!(n);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
