cp! {
input {
    x: u,
}

solve {
    fn do_it(c: &mut HashMap<(u, i), i>, a: u, sum: i) -> i {
        if sum < 0 {
            return -1;
        }

        if sum == 0 {
            return 0;
        }

        if c.contains_key(&(a, sum)) {
            return c[&(a, sum)];
        }

        let mut min = i::MAX;
        for i in 0..=9 {
            if a >> i & 1 == 0 {
                let res = do_it(c, a | 1 << i, sum - i);
                if res >= 0 {
                    let new = res * 10 + i;
                    if new < min {
                        min = new;
                    }
                }
            }
        }
        if min != i::MAX {
            c.insert((a, sum), min);
            return min;
        }

        c.insert((a, sum), -1);
        return -1;
    }

    let mut c = HashMap::new();
    let mut min = i::MAX;
    for i in 1..=9 {
        let res = do_it(&mut c, 1 << i, x as i - i);
        if res >= 0 {
        let new = res * 10 + i;
        if new < min {
            min = new;
        }
        }
    }
    ans!(if min != i::MAX {
        min
    } else {
        -1
    });
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
