fn do_it(c: &mut Cacher<i, i>, v: i) -> i {
    if v == 0 {
        return 0;
    }
    c.call(v, |c| {
        return do_it(c, v - 1) + 1;
    })
}

fn solve() {
    let mut c = Cacher::new();
    let ans = do_it(&mut c, 5);
    ans!(ans);
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

use algo::caching::Cacher;
#[cfg(not(ONLINE_JUDGE))]
use cp::*;
