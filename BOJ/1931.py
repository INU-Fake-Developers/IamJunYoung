import sys
input = sys.stdin.readline
n = int(input())

list = []
for i in range(0, n):
    start, last = map(int, input().split())
    list.append([last, start])

list.sort()
last = 0
cnt = 0
for time in list:
    if time[1] >= last:
        last = time[0]
        cnt += 1

print(cnt)
