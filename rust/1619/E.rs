fn solve() {
    input! {
        n: i,
        a: [i; n],
    }

    a.sort_unstable();

    let mut st = vii::new();
    let mut cost = 0;
    let mut idx = 0;
    for i in 0..=n {
        if i != 0 {
            if let Some((val, freq)) = st.pop() {
                cost += i - 1 - val;
                if freq > 1 {
                    st.push((val, freq - 1));
                }
            } else {
                ans!((i..=n).map(|_| -1),*);
            }
        }

        let mut freq = 0;
        while idx < n && a[idx.u()] == i {
            freq += 1;
            idx += 1;
        }
        if freq > 0 {
            st.push((i, freq));
        }

        let cost = cost + freq;
        print!("{} ", cost);
    }

    println!();
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
