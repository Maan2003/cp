import random

t = 1

print(t)
for _ in range(t):
    a = random.randint(1, 10**2)
    d = random.randint(1, 10**2)
    m = random.randint(1, 10**2)
    match random.randint(0, 2):
        case 0:
            print(a, a * m + d, a * m + 2 * d)
        case 1:
            print(a * m - d, a, a * m + d)
        case 2:
            print(a * m - 2 * d, a * m - d, a)

