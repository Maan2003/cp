fn solve() {
    input! {
        n: u, k: u8,
    }

    // generate pairs
    let mut used: HashSet<(u8, u8)> = HashSet::new();
    let mut s = Vec::new();
    for (i, j) in pairs(k) {
        if used.contains(&(i, j)) {
            continue;
        }
        match s.last() {
            Some(&last) => {
                if last == i {
                    s.push(j);
                } else {
                    s.push(i);
                    s.push(j);
                    used.insert((last, i));
                }
            }
            None => {
                s.push(i);
                s.push(j);
            }
        }
        used.insert((i, j));
    }

    let k = s.len();
    while s.len() < n {
        // TODO:
        if s[s.len() - 1] == s[0] {
            s.extend_from_within(1..);
        } else {
            s.extend_from_within(0..);
        }
    }
    s.truncate(n);
    unsafe { outln!(String::from_utf8_unchecked(s)) };
}

fn pairs(k: u8) -> impl Iterator<Item = (u8, u8)> {
    std::iter::successors(Some((0, 0)), move |&(mut i, mut j)| {
        j += 1;
        if j == k {
            i += 1;
            if i == k {
                return None;
            }
            j = 0;
        }
        Some((i, j))
    })
    .map(|(i, j)| (i + b'a', j + b'a'))
}

main!();

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
