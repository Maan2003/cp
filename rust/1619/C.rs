fn solve() {
    input! { a: i, s: i }
    let mut val: i = 0;
    let mut pos: i = 1;
    loop {
        if s == 0 && a != 0 {
            ans!(-1);
        }

        if s == 0 && a == 0 {
            ans!(val);
        }

        if s % 10 >= a % 10 {
            val += pos * (s % 10 - a % 10);
            s /= 10;
            a /= 10;
        } else {
            let dig = s % 100 - a % 10;
            if !(0..=9).contains(&dig) {
                ans!(-1);
            }
            val += pos * dig;
            s /= 100;
            a /= 10;
        }
        pos *= 10;
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
