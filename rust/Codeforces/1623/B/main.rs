fn solve() {
    input! {
        n: u,
        a: [(u, u); n],
    }

    a.sort_by_key(|&(x, y)| x as i - y as i);
    let mut s = m::<u, u>::new();

    let mut chs = v::<(u, u, u)>::new();
    for &(x, y) in &a {
        match (s.get(&x), s.get(&y)) {
            (Some(&z), _) if y < z => {
                chs.push((x, z, y + 1));
                if y + 2 <= n {
                    s.insert(z, y + 2);
                    s.insert(y + 2, z);
                }
            }
            (_, Some(&z)) if x > z => {
                chs.push((z, y, x - 1));
                if x > 2 {
                    s.insert(z, x - 2);
                    s.insert(x - 2, z);
                }
            }
            (_, _) => {}
        }
        if x == y {
            chs.push((x, y, x));
            continue;
        }
        s.insert(x, y);
        s.insert(y, x);
    }
    for (x, y, a) in chs {
        println!("{} {} {}", x, y, a);
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
