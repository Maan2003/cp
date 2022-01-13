#![allow(unused_parens)]
cp! {
kind = single;
input {
    n: u,
    k: i32,
    a: [i32; n],
}

solve {
    type i = i32;
    type u = usize;

    type Args = (u, i, i);
    type Out = i;

    fn solve(c: &mut HashMap<Args, Out>, a: &[i],
        args: Args,
    )
    -> Out
    {
        let (i, to_buy, to_sell) = args;
        if let Some(v) = c.get(&args) {
            return *v;
        }
        macro_rules! cb {($i:expr, $k1:expr, $k2:expr) => {
            solve(c, a, ($i, $k1, $k2))
        };}

        let val = {
            if to_buy < 0 || to_sell < 0 {
                return i::MIN / 2;
            }

            if i == a.len() || (to_buy == 0 && to_sell == 0) {
                return 0;
            }

            let sell_now = a[i] + cb!(i + 1, to_buy, to_sell - 1);
            let buy_now = -a[i] + cb!(i + 1, to_buy - 1, to_sell + 1);
            let noop = cb!(i + 1, to_buy, to_sell);
            sell_now.max(buy_now).max(noop)
        };
        c.insert(args, val);
        val
    }

    let mut c = HashMap::new();
    ans!(solve(&mut c, &a, (0, k, 0)));
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
