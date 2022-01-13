cp! {
input {
    n: u,
    m: u,
    a: [b; n],
    s: b,
}

solve {
    let mut v = v::new();
    for i in 0..n {
        // segment of atleast 2 length
        for j in 0..(m - 1) {
            let s = &a[i][j..];
            v.push(s);
        }
    }
    v.sort_unstable();
    let v2 = unsafe { std::mem::transmute::<&Vec<&[u8]>, &Vec<&str>>(&v) };
    let mut ans = vec![None; m + 1];
    ans[m] = Some((&[] as &[u8], None));
    'outer: for i in (0..m - 1).rev() {
        let suf = &s[i..];
        let suf2 = unsafe { std::mem::transmute::<&[u8], &str>(suf) };
        match v.binary_search(&suf) {
            Ok(idx) => {
                // total match
                ans[i] = Some((v[idx], None));
            },
            Err(idx) => {
                let mut match_len = 0;
                let mut s = &[] as &[u8];
                if idx != 0 {
                    let mut match_len2 = 0;
                    let a1 = v[idx - 1];
                    for j in 0..a1.len() {
                        if a1[j] != suf[j] {
                            break;
                        }
                        match_len2 += 1;
                    }
                    match_len = match_len2;
                    s = a1;
                }

                if idx != v.len() {
                    let a1 = v[idx];
                    let mut match_len2 = 0;
                    for j in 0..(a1.len().min(suf.len())) {
                        if a1[j] != suf[j] {
                            break;
                        }
                        match_len2 += 1;
                    }
                    if match_len2 > match_len {
                        match_len = match_len2;
                        s = a1;
                    }
                }

                if match_len < 2 {
                    ans[i] = None;
                    continue;
                }
                let s2 = unsafe { std::mem::transmute::<&[u8], &str>(s) };

                for k in (2..=match_len).rev() {
                    if ans[i + k].is_some() {
                        ans[i] = Some((&s[..k], Some(i + k)));
                        continue 'outer;
                    }
                }
            },
        }
    }

    let mut idx = 0;
    if ans[idx].is_none() {
        ans!(-1);
    }
    let mut cnt = 0;
    loop {
        if let Some((s, idx2)) = ans[idx] {
            if s.is_empty() {
                break;
            }
            // find the l and r
            for i in 0..n {
                let ptr = &s[0] as *const u8 as usize;
                let ptr2 = &a[i][0] as *const u8 as usize;
                if ptr - ptr2 < a[i].len() {
                    cnt += 1;
                    break;
                }
            }
            if let Some(idx3) = idx2 {
                idx = idx3;
            } else {
                break;
            }
        }
    }
    outln!(cnt);
    let mut idx = 0;
    loop {
        if let Some((s, idx2)) = ans[idx] {
            if s.is_empty() {
                break;
            }
            // find the l and r
            for i in 0..n {
                let ptr = &s[0] as *const u8 as usize;
                let ptr2 = &a[i][0] as *const u8 as usize;
                if ptr - ptr2 < a[i].len() {
                    outln!(ptr - ptr2 + 1, ptr - ptr2 + 1 + s.len() - 1, i + 1);
                    break;
                }
            }
            if let Some(idx3) = idx2 {
                idx = idx3;
            } else {
                break;
            }
        }
    }
}
}
#[cfg(not(ONLINE_JUDGE))]
#[macro_use]
extern crate cp;

#[cfg(not(ONLINE_JUDGE))]
use cp::*;
