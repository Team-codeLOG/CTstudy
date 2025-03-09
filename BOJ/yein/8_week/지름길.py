# 1446 지름길

N, D = map(int,input().split())

# 지름길 arr
arr = [list(map(int, input().split())) for _ in range(N)]

# 지름길을 출발 지점 기준으로 정렬
arr.sort()

# 지름길 없이 오는 경우를 뚜벅이라고 함 (차 타고 오지만 아무튼 그럼)
dp = [i for i in range(D+1)] # 전부 뚜벅이로 초기화

# 지름길 arr용 인덱스
k=0
for i in range(D+1):
    dp[i] = min(dp[i-1]+1, dp[i]) # 전 칸 + 1 또는 뚜벅이
    while (k<N): # N은 지름길의 총 개수
        if(i==arr[k][0]): # 지름길이 나 있는 길
            if(arr[k][1]<=D): # 지름길이 목표지점을 벗어난다면 무시
                dp[arr[k][1]] = min(dp[i]+arr[k][2], dp[arr[k][1]]) # 지름길이 뚜벅이보다 먼 경우가 있음. min을 통해 확실히 더 짧은 길 검증.
            k+=1
        else: break

print(dp[D])
