#!/usr/bin/env pypy3
import itertools
def wins(a, b):
    i1 = 0
    i2 = 0
    while True:
        if i1 == len(a) and i2 == len(b):
            return False
        if i1 == len(a):
            return True
        if i2 == len(b):
            return False
        if a[i1] > b[i2]:
            i2 += 1
        elif a[i1] < b[i2]:
            i1 += 1
        else:
            i1 += 1
            i2 += 1

def solve(a, b):
    b.sort()
    for perms in itertools.permutations(b):
        if wins(a, perms):
            print("YES")
            for v in perms:
                print(v, end=" ")
            print()
            return
    print("NO")
            

# generated by oj-template v4.8.1 (https://github.com/online-judge-tools/template-generator)
def main():
    t = int(input())
    for _ in range(t):
        _ = input()
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        solve(a, b)

if __name__ == '__main__':
    main()