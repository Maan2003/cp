cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    let mut a2 = vec![0; n];
    for i in 0..n {
        if i % 2 == 0 {
            a2[i] = a[i / 2];
        } else {
            a2[i] = a[n - 1 - i / 2];
        }
    }
    ans!(a2,*);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
