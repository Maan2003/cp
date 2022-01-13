cp! {
input {
   n: u,
   a: [i; n],
}

solve {
    for i in 0..n {
        a[i] -= i as i;
    }

    let m = freq_map(&a);
    let mut ans: u = 0;
    for &v in m.values() {
        if v == 1 {
            continue;
        }

        ans += (v * (v - 1)) / 2;
    }
    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
