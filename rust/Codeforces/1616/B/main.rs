fn solve() {
    input! {
        n: u,
        s: b,
    }

    // let last = true;
    let mut ans: u = 0;
    let mut last = true;
    for i in 1..n {
        // compare reversed string from s[i..0] and s[i - 2..0]
        if i == 1 {
            last = false;
        } else {
            match s[i].cmp(&s[i - 2]) {
                Ordering::Less => {
                    last = true;
                }
                Ordering::Equal => {}
                Ordering::Greater => {
                    last = false;
                }
            }
        }

        if s[i] > s[i - 1] {
            break;
        } else if s[i] == s[i - 1] && !last {
            break;
        }
        ans = i;
    }
    unsafe {
        out!(std::str::from_utf8_unchecked(&s[..=ans]));
        let rev: Vec<_> = s[..=ans].iter().copied().rev().collect();
        out!(String::from_utf8_unchecked(rev));
        println!();
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
