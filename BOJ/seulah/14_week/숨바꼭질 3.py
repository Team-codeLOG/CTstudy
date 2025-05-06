from collections import deque

N,K = map(int,input().split())
time = [-1]*100001

def bfs(n,k):
    if n == k:
        return 0
    queue = deque([(n)])
    time[n] = 0
    while queue:
        X = queue.popleft()
        for nx in [X-1,X+1,2*X]:
            if 0<=nx<=100000 and time[nx] ==-1:
                if nx == 2*X:
                    time[nx] = time[X]
                    queue.appendleft(nx)
                else:
                    time[nx] = time[X]+1
                    queue.append(nx)
    return time[k]

print(bfs(N,K))

