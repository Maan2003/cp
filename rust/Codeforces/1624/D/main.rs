cp! {
input {
    n: u,
    k: u,
    s: b,
}

solve {
    let mut freq: [u; 26] = [0; 26];
    for i in s {
        freq[i as usize - 'a' as usize] += 1;
    }

    let pairs = freq.iter().map(|x| x / 2).sum::<u>();
    let mut ans: u = 0;
    ans += 2 * (pairs / k);
    let left = pairs % k;
    let odd = n - pairs * 2 + left * 2;
    if odd >= k {
        ans += 1;
    }

    ans!(ans);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
