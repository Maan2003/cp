cp! {
input {
    n: u,
    a: [u; n],
}

solve {
    let mut heap = BinaryHeap::from(a);
    let mut turn: u = 0;
    let mut last = None;
    loop {
        let max = heap.pop();
        if max == None || max.unwrap() == 0 {
            break;
        }
        if let Some(last) = last {
            heap.push(last);
        }
        last = Some(max.unwrap() - 1);
        turn += 1;
    }
    if turn % 2 == 0 {
        ans!("HL");
    } else {
        ans!("T");
    }
}
}

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
