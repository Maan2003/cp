#!/usr/bin/env python3
# from typing import *


# def solve(testcases: int, a: List[str], b: List[str]) -> List[str]:
def solve(testcases, a, b):
    pass  # TODO: edit here


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    testcases = int(input())
    a = [None for _ in range(testcases)]
    b = [None for _ in range(testcases)]
    for i in range(testcases):
        a[i] = input()
        b[i] = input()
    c = solve(testcases, a, b)
    for i in range(testcases):
        print(c[i])


if __name__ == '__main__':
    main()
