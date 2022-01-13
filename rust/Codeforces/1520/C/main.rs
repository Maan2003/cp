cp! {
input {
    n: u,
}

solve {
    if n == 2 {
        ans!(-1);
    }
    let mut a = vec![vec![0; n]; n];
    let mut x = 1;
    for i in 0..n {
        a[i][i] = x;
        x+=1;
    }
    for offset in 1..n {
        for i in 0..n-offset {
            let j = i+offset;
            a[i][j] = x;
            x+=1;
        }
        for j in 0..n-offset {
            let i = j+offset;
            a[i][j] = x;
            x+=1;
        }
    }
    for i in 0..n {
        for j in 0..n {
            print!("{} ", a[i][j]);
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
