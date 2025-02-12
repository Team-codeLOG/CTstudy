N = int(input())
arr = []

for i in range(0, N):
    start, end = map(int, input().split())
    arr.append([start, end])

'''
# 종료시간 기준으로 정렬 (빠른 것이 뒤로, 같을 경우 시작 시간 고려)
for i in range(0, N):
    for j in range(i+1, N):
        if(arr[i][1] < arr[j][1]): arr[i], arr[j] = arr[j], arr[i]
        elif(arr[i][1] > arr[j][1]): continue
        else:
            if (arr[i][0] < arr[j][0]): arr[i], arr[j] = arr[j], arr[i]
'''
arr.sort(key=lambda x: (x[1], x[0]))

curr = 0
answer = 0
# 종료시간이 빠른 순서대로 담음
for start, end in arr:
    if(curr<=start):
        curr = end
        answer += 1
print(answer)

