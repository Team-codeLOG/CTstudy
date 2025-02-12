N, K = map(int, input().split())

arr = list(input())
cnt = 0

for i in range(N):
    e = arr[i]
    if (e == "P"):
        for j in range(max(0, i-K), min(i+K+1,N), 1):
            if (arr[j]=='H'):
                arr[j] = 'X'
                cnt += 1
                break

print(cnt)
    
