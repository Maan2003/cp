import random

n = random.randint(1, 10)
print(n)
for i in range(n):
    print(random.randint(-10 ** 2, 10 ** 2), end=' ')
print()
