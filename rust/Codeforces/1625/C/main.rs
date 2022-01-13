#![allow(unused_parens)]

type A = [[[i32; 2]; 500]; 500];

type i2 = i32;
cp! {
kind = single;
input {
    n: u,
    l: u,
    k: u,
    d: [i2; n],
    a: [i2; n],
}

solve {
    type Args = (u, i2, i2);
    type Out = i2;

    fn solve(c: &mut A, d: &[i2], a: &[i2], l: u,
        args: Args,
    )
    -> Out
    {
        let (i, last_sign, k) = args;
        if k < 0 {
            return i2::MAX / 2;
        }

        if c[i as u][last_sign as u][k as u] != -1 {
            return c[i][last_sign as u][k as u];
        }
        macro_rules! cb {($i:expr, $k1:expr, $k2:expr) => {
            solve(c, d, a, l, ($i, $k1, $k2 % 2))
        };}

        let val = {
            if i == a.len() - 1 {
                return 0;
            }

            min(
                a[i] * (d[i + 1] - d[i]) + cb!(i + 1, i as i32, k),
                a[last_sign as u] * (d[i + 1] - d[i]) + cb!(i + 1, last_sign, k - 1),
            )
        };
        c[i as u][last_sign as u][k as u] = val;
        val
    }

    let mut c: Box<A> = unsafe { Box::new(uninitialized()) };
    a.push(0);
    d.push(l as i2);
    ans!(a[0] * (d[1] - d[0]) + solve(&c, &d, &a, l, (1, 0 as i32, k as i2)));
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
