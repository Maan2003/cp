use std::mem::swap;

use rand::{prelude::SmallRng, *};
fn main() {
    let mut rng = SmallRng::from_rng(thread_rng()).unwrap();

    for i in 0usize.. {
        if i % 10000000 == 0 {
            println!("{}", i);
        }
        let mut a = rng.gen_range(1..10000usize);
        let mut b = rng.gen_range(1..10000usize);
        let mut c = rng.gen_range(1..10000usize);

        // 2 3 1
        if a > b {
            swap(&mut a, &mut b);
        }

        if b > c {
            swap(&mut b, &mut c);
        }

        if a > b {
            swap(&mut a, &mut b);
        }

        if (b - a) * c > (c - a) * b {
            println!("{} {} {}", a, b, c);
            break;
        }
    }
}
