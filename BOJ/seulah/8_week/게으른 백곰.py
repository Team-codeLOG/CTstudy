from sys import stdin

n, k = map(int, stdin.readline().split())
length, ans = 0, 0
arr = [0] * 10000001

for _ in range(n):
    g, x = map(int, stdin.readline().split())
    length = max(length, x)
    arr[x] = g

p = k * 2 + 1
res = sum(arr[:p])
ans = res

for i in range(p, length + 1):
    res += (arr[i] - arr[i - p])
    ans = max(ans, res)

print(ans)