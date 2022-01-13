cp! {
input {
    n: u,
    k: u,
}

rand {
    n = r(1..=10);
    k = r(1..=100);
}

solve {
    if 2 * k - 1 > n {
        ans!(-1);
    }

    for i in 0..n {
        for j in 0..n {
            if i == j && i % 2 == 0 && k > 0 {
                k -= 1;
                print!("R");
            } else {
                print!(".");
            }
        }
        println!();
    }
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
