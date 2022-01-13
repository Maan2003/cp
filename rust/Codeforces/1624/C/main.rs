cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    let mut b = vec![0; n + 1];
    for i in 0..n {
        let mut temp = a[i];
        while temp > n {
            temp /= 2;
        }
        b[temp] += 1;
    }

    for x in (1..=n).rev() {
        if b[x] == 0 {
            ans!(NO);
        }
        b[x / 2] += b[x] - 1;
        b[x] = 0;
    }

    ans!(YES);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
