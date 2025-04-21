from collections import deque

N = int(input()) # 컴퓨터 수
K = int(input()) # 페어 수

computers = [[] for _ in range(N+1)]
visited =[0]*(N+1)

for _ in range(K):
    x,y = map(int,input().split())
    computers[x].append(y)
    computers[y].append(x) #양방향 연결

def bfs(start):
    cnt = 0
    queue = deque([start])
    visited[start] = 1

    while queue:
        cur = queue.popleft()
        for computer in computers[cur]:
            if not visited[computer]:
                visited[computer]=1
                queue.append(computer)
                cnt+=1
    return cnt

print(bfs(1))
