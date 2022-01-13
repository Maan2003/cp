cp! {
input {
    n: u,
    a: [b; n],
}

solve {
    let mut ans = [0; 26];
    for i in 0..n {
        for j in 0..a[i].len() {
            ans[a[i][j] as usize - 'a' as usize] += 1;
        }
    }

    for i in 0..26 {
        if ans[i] % n != 0 {
            ans!(NO);
        }
    }
    ans!(YES);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
