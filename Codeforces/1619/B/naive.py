#!/usr/bin/env pypy3
def solve(n):
    s = set()
    for i in range(1, n):
        if (i * i) <= n:
            s.add(i * i)
        if (i * i * i) <= n:
            s.add(i * i * i)
    return len(s)


def main():
    n = int(input())  
    for _ in range(n):
        print(solve(int(input())))

if __name__ == '__main__':
    main()
