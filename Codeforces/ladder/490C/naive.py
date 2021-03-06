#!/usr/bin/env python3
# from typing import *

YES = 'YES'
NO = 'NO'


# def solve(a: str, b: int, c: int) -> Any:
def solve(a, b, c):
    for i in range(1, len(a)):
        if a[i] == '0':
            continue
        if (int(a[:i]) % b == 0) and (int(a[i:]) % c == 0):
            print(YES)
            print(a[:i])
            print(a[i:])
            return
    print(NO)


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    a = input()
    b, c = map(int, input().split())
    solve(a, b, c)


if __name__ == '__main__':
    main()
