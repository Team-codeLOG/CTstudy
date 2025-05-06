# 수빈이의 위치, 동생의 위치
subin, sister = map(int, input().split())

# 모든 가능한 위치에 대해서, 점수판
# 주의 :: scores[0] 은 1번째가 아니라 0번째임...
MAX = 100000
scores = [-1 for _ in range(MAX+1)]

# 수빈이의 현재 위치 == 현재 방문지, 방문한 적 있음.
scores[subin] = 0

# bfs로 풀 것임
from collections import deque
dq = deque()
dq.append(subin)

## 주의 :: 수빈이가 동생보다 앞에 있다면, 무조건 뒤로만 "걸어야" 함 !!
if (subin >= sister): print(subin-sister)
else:
  while(dq):
    curr = dq.popleft()
    time = scores[curr]
    # 현 위치 == 동생 위치
    if (curr == sister):
      print(time)
      break
    # 현 위치 != 동생 위치 : 동생 찾으러 이동!
    # -1이 아니라면 이미 들렀던 곳이고, 로직상 이미 들렀던 곳이 더 빨리 도착한 케이스이므로 업데이트하지 않는다.
    # ~라고 생각했는데 아니었다....
    # 주의 :: 인덱스 에러 - 인덱스를 검증해준다.
    # 앞으로 가기
    if (curr+1 <= MAX and (scores[curr+1]==-1 or scores[curr+1]>time+1)):
      scores[curr+1] = time+1
      dq.append(curr+1)
    # 뒤로 가기
    if (curr-1 >= 0 and (scores[curr-1]==-1 or scores[curr-1]>time+1)):
      scores[curr-1] = time+1
      dq.append(curr-1)
    # 순간이동
    if (curr*2 <= MAX and (scores[curr*2]==-1 or scores[curr*2]>time)):
      scores[curr*2] = time
      dq.append(curr*2)