#!/usr/bin/env python3
# from typing import *


# def solve(a: int, b: List[int], c: List[int], d: List[int]) -> Tuple[int, int]:
def solve(a, b, c, d):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    a = int(input())
    b = [None for _ in range(a)]
    c = [None for _ in range(a)]
    d = [None for _ in range(a)]
    for i in range(a):
        b[i] = int(input())
        c[i], d[i] = map(int, input().split())
    g, h = solve(a, b, c, d)
    print(g)
    print(h)


if __name__ == '__main__':
    main()