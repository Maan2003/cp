#!/bin/pypy3
import random

def main():
    print(1000000);
    for _ in range(1000000):
        a = 3
        print(a);
        for _ in range(a):
            print(random.randint(1, 10000000))


if __name__ == "__main__":
    main()
