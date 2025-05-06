# N: 퇴사까지 남은 날
N = int(input())

# dp: idx번째까지 일했을 때의 최대 수익
# 인덱스 주의 :: dp[0] != 1일차
dp = [0 for _ in range(N+1)]

for i in range(N):
  # 상담시간 T와 상담비용 P
  time, price = map(int, input().split())
  today = i+time
  for j in range(today, N+1):
    if(dp[j]<dp[i]+price): dp[j] = dp[i] + price

print(dp[-1])