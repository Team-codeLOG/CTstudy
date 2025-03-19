import sys
input = sys.stdin.readline

n = int(input())
wine = [int(input()) for _ in range(n)]

# dp[i] : i번째까지 마셨을 때의 최대 와인 양
dp = [0] * n

# 첫 번째 와인만 마시는 경우
dp[0] = wine[0]

# 두 번째 와인까지 마시는 경우
if n > 1:
    dp[1] = wine[0] + wine[1]  # 와인 0과 1을 모두 마신 경우

# 세 번째 와인까지 마시는 경우
if n > 2:
    dp[2] = max(wine[0] + wine[2], wine[1] + wine[2], dp[1])

# 나머지 경우에 대해 dp 배열을 채워나가기
for i in range(3, n):
    dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i], dp[i-1])

print(dp[n-1])
