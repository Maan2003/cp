#!/usr/bin/env python3
# usage: $ oj generate-input 'python3 generate.py'
# usage: $ oj generate-input --hack-actual=./a.out --hack-expected=./naive 'python3 generate.py'
import random


# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    n = 1
    a = [None for _ in range(n)]
    for i in range(n):
        a[i] = ''.join([random.choice('abcdefg') for _ in range(random.randint(4, 10))])  # TODO: edit here
    print(n)
    for i in range(n):
        print(a[i])


if __name__ == "__main__":
    main()