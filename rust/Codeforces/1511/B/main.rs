const PRIMES: [(u, u); 9] = [
    (2, 3),
    (43, 47),
    (211, 149),
    (5039, 1297),
    (65537, 19441),
    (112909, 115249),
    (2097593, 3010349),
    (13466917, 31636373),
    (370248451, 433494437),
];

const TENS: [u; 9] = [
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
];
fn solve() {
    input! {
        a: u, b: u, c: u,
    }
    let a = a - c + 1;
    let b = b - c + 1;
    let ten = TENS[c - 1];
    ans!(PRIMES[a - 1].0 * ten, PRIMES[b - 1].1 * ten);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
