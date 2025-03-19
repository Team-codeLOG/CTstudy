# n: 포도주 잔 개수
# arr: 잔마다 들어 있는 포도주 양
n = int(input())
arr = []

# dp : 각 시도별 최대로 마실 수 있는 포도주의 양
# memo : 마셨던 포도주 체크
dp = [0 for _ in range(n)]
memo = []


# 포도주 양을 받는다
for i in range(n):
    wine = int(input())
    arr.append(wine)

# 3잔 이상일 때만 계산 수행
if (n>2):
    print(n)
    # dp 배열의 초기값들 설정
    dp[0] = arr[0]
    dp[1] = arr[0]+arr[1]
    dp[2] = max(arr[0]+arr[1], arr[0]+arr[2], arr[1]+arr[2])

    # dp[i] = arr[i]를 포함하는 케이스 중 최대
    for i in range(3, n):
        case1 = dp[i-1] # arr[i] 제외
        case2 = dp[i-2]+arr[i] # arr[i-1] 제외
        case3 = dp[i-3]+arr[i-1]+arr[i] # arr[i-2] 제외
        dp[i] = max(case1, case2, case3)
    print(n)

# 총 2잔 이하면 원샷~~!
else:
    print(sum(arr))

