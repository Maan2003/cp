fn solve() {
    input! {
        n: u,
        a: b,
        b: b,
    }

    let mut z1: i = 0;
    let mut o0: i = 0;
    let mut z1r: i = 0;
    let mut o0r: i = 0;

    for i in 0..n {
        match (a[i] - b'0', b[i] - b'0') {
            (0, 1) => z1 += 1,
            (1, 0) => o0 += 1,
            (1, 1) => z1r += 1,
            (0, 0) => o0r += 1,
            _ => unreachable!(),
        }
    }

    let mut ans = i::MAX;
    if z1 == o0 {
        let a = 2 * z1;
        if a < ans {
            ans = a;
        }
    }
    if z1r == o0r + 1 {
        let a = 1 + 2 * o0r;
        if a < ans {
            ans = a;
        }
    }
    if z1r + 1 == o0r && o0 != 0 {
        let a = 1 + 2 * o0r;
        if a < ans {
            ans = a;
        }
    } 
    if ans == i::MAX {
        ans!(-1);
    } else {
        ans!(ans);
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
