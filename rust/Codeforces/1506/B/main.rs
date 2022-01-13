fn solve() {
    input! {
        n: u, k: u,
        s: b,
    }

    // pos
    let mut pos = match s.iter().position(|b| *b == b'*') {
        Some(pos) => pos,
        None => {
            ans!(0);
        }
    };

    let mut ans: u = 1;
    s[pos] = b'+';
    'outer: while pos < n {
        let mut next = (pos + k).min(n - 1);
        loop {
            if s[next] == b'*' {
                s[next] = b'+';
                pos = next;
                break;
            }
            if next <= pos {
                break 'outer;
            }
            next -= 1;
        }
        ans += 1;
    }
    ans!(ans);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
