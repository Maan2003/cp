import sys
# input
with open(sys.argv[1]) as testcase:
    n = int(testcase.readline())
    a = list(map(int, testcase.readline().split()))
with open(sys.argv[2]) as your_output:
    x1, x2 = map(int, your_output.readline().split())
    x1s = list(map(int, your_output.readline().split()))
    y1, y2 = map(int, your_output.readline().split())
    y1s = list(map(int, your_output.readline().split()))
    z1, z2 = map(int, your_output.readline().split())
    z1s = list(map(int, your_output.readline().split()))


for i in range(x1 - 1, x2):
    a[i] += x1s[i - x1 + 1]

for i in range(y1 - 1, y2):
    a[i] += y1s[i - y1 + 1]

for i in range(z1 - 1, z2):
    a[i] += z1s[i - z1 + 1]

for i in range(n):
    assert a[i] == 0

