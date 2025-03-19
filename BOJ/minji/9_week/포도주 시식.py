import sys
input = sys.stdin.readline

n = int(input())
wine = [int(input()) for _ in range(n)]

dp = [0] * n

# 첫 번째 와인만 마시는 경우
dp[0] = wine[0]

# 두 번째 와인까지 마시는 경우 - 와인 0과 1을 모두 마심
if n > 1:
    dp[1] = wine[0] + wine[1]


# 세 번째 와인까지 마시는 경우 - 0,2 / 1,2 / 1 중 가장 큰 값값
if n > 2:
    dp[2] = max(wine[0] + wine[2], wine[1] + wine[2], dp[1])

# 나머지 경우 - i-2, i / i-3, i-1, i / i-1 중 최대값
for i in range(3, n):
    dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i], dp[i-1])

print(dp[n-1])
