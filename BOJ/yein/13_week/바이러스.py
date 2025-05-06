# DFS로 풀기
# N = 컴퓨터의 수
N=int(input())

# M = 컴퓨터 쌍의 수
M = int(input())
# 컴퓨터 쌍
dict = {}
for _ in range(M):
  a, b = map(int, input().split())
  if(a not in dict):
    dict[a] = [b]
  else:
    dict[a].append(b)
  if(b not in dict):
    dict[b] = [a]
  else:
    dict[b].append(a)

# print(dict)

# 탐색 시작~
curr = 1
global ans
ans = 0
visited = []

def dfs(curr):
  global ans
  if(curr in dict):
    for c in dict[curr]:
      if (c not in visited):
        visited.append(c)
        if (not c==1): ans += 1
        dfs(c)

dfs(curr)
print(ans)

# # BFS로 구현
# # N = 컴퓨터의 수
# N=int(input())

# # M = 컴퓨터 쌍의 수
# M = int(input())
# # 컴퓨터 쌍
# dict = {}
# for _ in range(M):
#   a, b = map(int, input().split())
#   if(a not in dict):
#     dict[a] = [b]
#   else:
#     dict[a].append(b)
#   if(b not in dict):
#     dict[b] = [a]
#   else:
#     dict[b].append(a)

# from collections import deque
# q = deque()
# curr = 1
# # global ans
# ans = 0
# visited = []

# def bfs(curr):
#   global ans
#   q.append(curr)
#   visited.append(curr)
#   while(q):
#     curr= q.popleft()
#     if(curr in dict):
#       for c in dict[curr]:
#         if(c not in visited):
#           visited.append(c)
#           if (not c==1): ans += 1
#           q.append(c)

# bfs(curr)
# print(ans)