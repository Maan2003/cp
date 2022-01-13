cp! {
input {
    n: u,
    s: b,
}

solve {
    let x = (s.starts_with(b"2") && s.ends_with(b"020")) || s.starts_with(b"2020") || s.ends_with(b"2020")
        || (s.starts_with(b"20") && s.ends_with(b"20")) || (s.starts_with(b"202") && s.ends_with(b"0"));
    ans!(yn(x));
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
