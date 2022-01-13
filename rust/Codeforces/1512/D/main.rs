fn solve() {
    input! {
        n: u,
        b: [i; n + 2],
    }
    b.sort_unstable();
    // eliminate last elem
    // sum is second last elem
    let sum = b[n];
    if b[0..n].iter().sum::<i>() == sum {
        ans!(&b[0..n],*);
    }

    // sum is last elem of b
    // second last is x
    let sum = b[n + 1];
    let x = b[0..=n].iter().sum::<i>() - sum;
    if let Some(pos) = b[0..=n].iter().position(|&i| i == x) {
        for i in 0..=n {
            if i != pos {
                print!("{} ", b[i]);
            }
        }
        println!();
    } else {
        ans!(-1);
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
