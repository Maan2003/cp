cp! {
kind = single;
input {
    n: u, m: u, q: u,
    qs: [u; q],
}

solve {
    let mut grid = Box::new([0; 1000 * 1000]);
    let mut cnt = {
        let mut cnt = 0;
        // iterate over all the diagonals of grid
        // diagonal starts at (0, j)
        for j in 0..m {
            let len = min(m - j, n);
            outln!(len);
            cnt += len * len;
        }
        for i in 1..n {
            let len = min(n - i, m);
            outln!(len);
            cnt += len * len;
        }
        cnt
    };
    println!("{}", cnt);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
