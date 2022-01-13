cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    a.sort_by_key(|&x| -(x as i));
    let mut ax: u = 0;
    let mut bx: u = 0;
    for i in 0..n {
        if i % 2 == 0 {
            // alice
            if a[i] % 2 == 0 {
                ax += a[i];
            }
        } else {
            // bob
            if a[i] % 2 == 1 {
                bx += a[i];
            }
        }
    }
    if ax > bx {
        println!("Alice");
    } else if ax < bx {
        println!("Bob");
    } else {
        println!("Tie");
    }
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
