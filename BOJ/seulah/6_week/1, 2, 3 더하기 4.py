
import sys
input= sys.stdin.readline

dp = [1] * 10001
for i in range(2, 10001):
    dp[i] += dp[i - 2]
for i in range(3, 10001):
    dp[i] += dp[i - 3]

T = int(input())
for _ in range(T):
    N = int(input())
    print(dp[N])
