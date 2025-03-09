N,D = map(int,input().split())
shortcut = []
for _ in range(N):
    start,end,length = map(int,input().split())
    if end-start > length:
        shortcut.append([start,end,length])

shortcut.sort()

dp = [i for i in range(D+1)]

for start,end,length in shortcut:
    for i in range(1, D+1):
        if i == end :
            dp[i] = min(dp[i],dp[start]+length)
        else:
            dp[i] = min(dp[i],dp[i-1]+1)

print(dp[D])