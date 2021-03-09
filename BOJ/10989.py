import sys
n = int(input())
cnt = [0] * 10001

for i in range(0, n):
    inp = int(sys.stdin.readline().rstrip())
    cnt[inp] += 1

for i in range(0, 10):
    for j in range(0, cnt[i]):
        print(i)
