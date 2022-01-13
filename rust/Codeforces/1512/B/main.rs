fn solve() {
    input! {
        n: usize,
        a: [bytes; n],
    }
    let mut v: Vec<(u, u)> = vec![];
    for i in 0..n {
        for j in 0..n {
            if a[i][j] == b'*' {
                v.push((i, j));
            }
        }
    }

    let (x1, y1) = v[0];
    let (x2, y2) = v[1];

    let (x3, y3, x4, y4) = if y1 == y2 {
        if y1 == n - 1 {
            (x1, 0, x2, 0)
        } else {
            (x1, y1 + 1, x2, y1 + 1)
        }
    } else if x1 == x2 {
        if x1 == n - 1 {
            (0, y1, 0, y2)
        } else {
            (x1 + 1, y1, x1 + 1, y2)
        }
    } else {
        (x1, y2, x2, y1)
    };

    for i in 0..n {
        for j in 0..n {
            let ij = (i, j);
            if ij == (x1, y1) || ij == (x2, y2) || ij == (x3, y3) || ij == (x4, y4) {
                print!("*");
            } else {
                print!(".");
            }
        }
        println!();
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
