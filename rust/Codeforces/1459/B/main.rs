cp! {
kind = single;
input {
    n: u,
}

naive {
    fn solve(r: &mut HashSet<(i, i)>, cache: &mut HashSet<(u, (i, i), bool)>, n: u, loc: (i, i), last: bool) {
        if cache.contains(&(n, loc, last)) {
            return;
        }
        cache.insert((n, loc, last));
        if n == 0 {
            r.insert(loc);
            return;
        }

        // last = true => last move was horizontal
        if last {
            solve(r, cache, n - 1, (loc.0, loc.1 + 1), !last);
            solve(r, cache, n - 1, (loc.0, loc.1 - 1), !last);
        } else {
            solve(r, cache, n - 1, (loc.0 + 1, loc.1), !last);
            solve(r, cache, n - 1, (loc.0 - 1, loc.1), !last);
        }
    }

    let mut cache = HashSet::new();
    let mut r = HashSet::new();
    solve(&mut r, &mut cache, n, (0, 0), true);
    solve(&mut r, &mut cache, n, (0, 0), false);
    ans!(r.len());
}

solve {
    fn count(n: u) -> u {
        let mut s = HashSet::new();
        for i in 0..=n {
            s.insert(i as i - (n - i) as i);
        }
        s.len()
    }

    if n % 2 == 0 {
        let val = count(n / 2);
        ans!(val * val);
    } else {
        ans!(count(n / 2) * count(n / 2 + 1) * 2);
    }
}

}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
