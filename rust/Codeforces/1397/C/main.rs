cp! {
kind = single;
input {
    n: u,
    a: [i; n],
}

solve {
    if n == 1 {
        println!("1 1");
        outln!(-a[0]);
        println!("1 1");
        outln!(0);
        println!("1 1");
        outln!(0);
        return;
    }
    let b1 = n - 1;
    let b2 = n;
    println!("1 1");
    outln!(-a[0]);
    println!("1 {}", n);
    out!(0,);
    for i in 1..n {
        out!(- a[i] * n as i,);
    }
    println!();
    println!("2 {}", n);
    for i in 1..n {
        out!(a[i] * (n as i - 1),);
    }
    println!();
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
