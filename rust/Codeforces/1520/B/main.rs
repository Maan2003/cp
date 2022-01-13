cp! {
input {
    n: u64,
}

rand {
    n = r(1..=100);
}

naive {
    let mut ans = 0;
    for mut i in 1..=n {
        let dig = i % 10;
        ans += 1;
        while i > 0 {
            if i % 10 != dig {
                ans -= 1;
                break;
            }
            i /= 10;
        }
    }
    ans!(ans);
}

solve {
    let mut digs: u = 0;
    let mut temp = n;
    while temp > 0 {
        temp /= 10;
        digs += 1;
    }

    let mut cur_dig = 0;
    for i in 1..=9 {
        let mut num = 0;
        for j in 0..digs {
            num += i * 10u64.pow(j as u32);
        }
        if num <= n {
            cur_dig += 1;
        }
    }

    ans!(9 * (digs - 1) + cur_dig);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
