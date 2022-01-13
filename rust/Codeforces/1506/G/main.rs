fn solve() {
    input! {
        s: b,
    }

    for c in b'a'..=b'z' {
        let s2 = Vec::with_capacity(s.len());
        let cnt = s.iter().filter(|&&x| x == c).count();
        let removed = HashSet::new();
        if cnt > 1 {
            // first remove the value followed by bigger values
            for i in 0..s.len() - 1 {
                if s[i]
            }
        }
    }
    
    
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
