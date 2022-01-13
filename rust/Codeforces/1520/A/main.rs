cp! {
input {
    n: u,
    s: b,
}

solve {
    for i in b'A'..=b'Z' {
        enum Mode {
        Start,
        Ended,
        Running,
        }
        let mut mode = Mode::Start;
        for &b in &s {
            match mode {
            Mode::Start => {
                if b == i {
                    mode = Mode::Running;
                }
            }
            Mode::Running => {
                if b == i {
                    mode = Mode::Running;
                } else {
                    mode = Mode::Ended;
                }
            }
            Mode::Ended => {
                if b == i {
                    ans!(NO);
                }
            }
            }
        }
    }
    ans!(YES);
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
