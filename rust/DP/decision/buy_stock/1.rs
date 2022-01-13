#![allow(unused_parens)]
cp! {
kind = single;
input {
    n: u,
    a: [i32; n],
}

solve {
    type Args = (u, bool);
    type i = i32;
    type Out = i;
    type u = usize;

    fn solve(c: &mut HashMap<Args, Out>, a: &[i],
        args: Args,
    )
    -> Out
    {
        let (i, buy) = args;
        if let Some(v) = c.get(&args) {
            return *v;
        }
        macro_rules! cb {($i:expr, $sold:expr) => {
            solve(c, a, ($i, $sold))
        };}

        let val = {
            if i == a.len() {
                return 0;
            }

            if buy {
                // sell now or later
                max(cb!(i + 1, true), a[i])
            } else {
                max(cb!(i + 1, true) - a[i], cb!(i + 1, false))
            }
        };
        c.insert(args, val);
        val
    }

    let mut c = HashMap::new();
    solve(&mut c, &a, (0, false))
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
