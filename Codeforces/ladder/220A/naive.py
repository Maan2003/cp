#!/usr/bin/env python3
# from typing import *

YES = 'YES'
NO = 'NO'


# def solve(n: int, a: List[int]) -> str:
def solve(n, a):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    import sys
    tokens = iter(sys.stdin.read().split())
    n = int(next(tokens))
    a = [None for _ in range(n)]
    for i in range(n):
        a[i] = int(next(tokens))
    assert next(tokens, None) is None
    a1 = solve(n, a)
    print(a1)


if __name__ == '__main__':
    main()