fn solve() {
    input! {
        n: u, q: u,
        a: [u; n],
        q: [u; q],
    }

    let mut idxs = [0; 51];

    for i in 1..=n {
        if idxs[a[i - 1]] == 0 {
            idxs[a[i - 1]] = i;
        }
    }

    for q in q {
        let val = idxs[q];
        for x in 1..=50 {
            if idxs[x] < val {
                idxs[x] += 1;
            }
        }
        idxs[q] = 1;
        out!(val,);
    }

    outln!();
}

main!();

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
