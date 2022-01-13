fn solve() {
    input! {
        n: i, l: i, r: i, s: i,
    }
    let cnt = (r - l + 1) as i;
    let mut v: vi = (1..=n).collect();
    let mut diff = s - ((cnt + 1) * cnt) / 2;
    let mut l1 = 0;
    let mut r1 = v.len() - 1;
    while l1 < cnt as u && r1 >= cnt as u {
        if diff <= 0 {
            break;
        }
        if v[r1] - v[l1] > diff {
            if (l1 as i) < cnt - 1 {
                l1 += 1;
            } else {
                r1 -= 1;
            }
        } else {
            diff -= v[r1] - v[l1];
            v.swap(l1, r1);
            l1 += 1;
            r1 -= 1;
        }
    }
    if diff != 0 {
        ans!(-1);
    }

    let mut left = v[cnt.u()..].iter();
    let mut mid = v[..cnt.u()].iter();
    for _ in 1..l {
        print!("{} ", left.next().unwrap());
    }

    for _ in l..=r {
        print!("{} ", mid.next().unwrap());
    }

    for _ in r + 1..=n {
        print!("{} ", left.next().unwrap());
    }

    println!();
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
