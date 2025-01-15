n = int(input())
sizes = [list(map(int,input().split())) for _ in range(n)]

for i in range(n):
    rank = 1
    for j in range(n):
        if sizes[i][0] < sizes[j][0] and sizes[i][1] < sizes[j][1]:
            rank +=1
    print(rank, end=' ')