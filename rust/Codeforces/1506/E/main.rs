fn solve() {
    input! {
        n: u,
        q: [u; n],
    }

    {
        let mut max = 0;
        let mut heap = BinaryHeap::new();
        let mut ans = vec![];
        for i in 0..n {
            if max < q[i] {
                ans.push(q[i]);
                for i in max + 1..q[i] {
                    heap.push(Reverse(i));
                }
                max = q[i];
            } else {
                ans.push(heap.pop().unwrap().0);
            }
        }
        output!(ans,*;);
    }
    {
        let mut max = 0;
        let mut heap = BinaryHeap::new();
        let mut ans = vec![];
        for i in 0..n {
            if max < q[i] {
                ans.push(q[i]);
                for i in max + 1..q[i] {
                    heap.push(i);
                }
                max = q[i];
            } else {
                ans.push(heap.pop().unwrap());
            }
        }
        output!(ans,*;);
    }
}

main!(multi);

#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
