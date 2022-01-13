use aoc_runner_derive::*;

#[aoc(day13, part1, Bytes)]
pub fn part1_bytes(input: &[u8]) -> i32 {
    input.iter().fold(0, |sum, c| match c {
        b'(' => sum + 1,
        b')' => sum - 1,
        _ => unreachable!(),
    })
}

#[aoc(day13, part1, Chars)]
pub fn part1_chars(input: &str) -> i32 {
    input.chars().fold(0, |sum, c| match c {
        '(' => sum + 1,
        ')' => sum - 1,
        _ => unreachable!(),
    })
}

#[aoc(day13, part2)]
pub fn part2(input: &str) -> usize {
    let mut sum: u32 = 0;

    for (i, c) in input.as_bytes().iter().enumerate() {
        match c {
            b'(' => sum += 1,
            b')' => {
                if let Some(s) = sum.checked_sub(1) {
                    sum = s;
                } else {
                    return i + 1;
                }
            }
            _ => unreachable!(),
        }
    }

    unreachable!()
}

