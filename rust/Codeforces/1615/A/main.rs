fn solve() {
    input! {
        n: u,
        a: [u; n],
    }
    
    let sum = a.iter().sum::<u>();
    if sum % n == 0 {
        ans!(0);
    } else {
        ans!(1);
    }
    
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
