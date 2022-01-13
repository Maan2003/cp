fn solve() {
    input! {
        n: u,
        a: [u; n],
    }

    let (mut x, mut y, mut z): (u, u, u) = (0, 0, 0);
    for &w in &a {
        match w % 3 {
            0 => x += 1,
            1 => y += 1,
            2 => z += 1,
            _ => unreachable!(),
        }
    }

    let mut v = vec![(x, 0), (y, 1), (z, 2)];
    v.sort();

    let mut ans: u = 0;
    while v[0].0 < n / 3 {
        let C = |a, b| match (a, b) {
            (1, 2) => 1,
            (2, 0) => 1,
            (0, 1) => 1,
            (x, y) if x == y => 0,
            _ => 2,
        };
        let cost2 = C(v[2].1, v[0].1);
        let cost1 = C(v[1].1, v[0].1);

        let mv1 = (v[1].0 as i - (n / 3) as i)
            .min((n / 3 - v[0].0) as i)
            .max(0) as u;
        let mv2 = (v[2].0 as i - (n / 3) as i)
            .min((n / 3 - v[0].0) as i)
            .max(0) as u;

        if mv1 != 0 && cost1 < cost2 {
            ans += mv1 * cost1;
            v[1].0 -= mv1;
            v[0].0 += mv1;
        } else {
            ans += mv2 * cost2;
            v[2].0 -= mv2;
            v[0].0 += mv2;
        }

        v.sort();
    }
    ans!(ans);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
