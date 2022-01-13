cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    let mut c = vec![0; n];
    for i in (0..n).rev() {
        c[i] = a[i];
        let ni = a[i] + i;
        if ni < n {
            c[i] += c[ni];
        }
    }
    ans!(c.iter().max().unwrap());
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
