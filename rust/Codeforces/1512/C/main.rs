fn solve() {
    input! {
        a: u,
        b: u,
        s: b,
    }

    for i in 0..(s.len() + 1) / 2 {
        let l = s[i];
        let r = s[s.len() - 1 - i];
        if l == r {
            continue;
        }
        if l == b'?' {
            s[i] = r;
        } else if r == b'?' {
            let idx = s.len() - 1 - i;
            s[idx] = l;
        } else {
            ans!(-1);
        }
    }

    let mut qs: u = 0;
    let mut ones = b as i;
    let mut zeros = a as i;
    for i in 0..s.len() {
        if s[i] == b'?' {
            qs += 1;
        } else if s[i] == b'1' {
            ones -= 1;
        } else {
            zeros -= 1;
        }
    }

    for i in 0..(s.len() + 1) / 2 {
        if s[i] == b'?' {
            let idx = s.len() - 1 - i;
            let change = if i == s.len() / 2 { 1 } else { 2 };
            if ones >= change {
                s[i] = b'1';
                s[idx] = b'1';
                ones -= change;
            } else if zeros >= change {
                s[i] = b'0';
                s[idx] = b'0';
                zeros -= change;
            } else {
                ans!(-1);
            }
        }
    }
    if ones != 0 || zeros != 0 {
        ans!(-1);
    } else {
        ans!(unsafe { String::from_utf8_unchecked(s) });
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
