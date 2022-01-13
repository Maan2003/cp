fn solve() {
    input! {
        n: u,
        a: [u; n],
    }

    let f: vu = freq_map(&a).into_iter().map(|(_val, freq)| freq).collect();
    let mut f: vuu = freq_map(&f).into_iter().collect();
    f.sort_unstable();
    let mut c1: u = 0;
    let mut c2: u = f.iter().map(|(f, ff)| f * ff).sum::<u>();
    let mut ff_sum: u = f.iter().map(|(_, ff)| ff).sum::<u>();
    let mut val = n;
    for (f, ff) in f {
        ff_sum -= ff;
        c2 -= f * ff;

        val = val.min(c1 + c2 - f * ff_sum);

        c1 += f * ff;
    }
    ans!(val);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
