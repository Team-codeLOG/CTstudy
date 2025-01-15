N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())))

rank = [1 for _ in range(N) ]

for i in range(N):
    for j in range(N):
        if arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]:
            rank[i] += 1

print(*rank)
