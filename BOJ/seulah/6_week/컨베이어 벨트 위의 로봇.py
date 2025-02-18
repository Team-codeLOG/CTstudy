import sys
from collections import deque
input = sys.stdin.readline

N,K = map(int,input().split())
belt = deque(map(int,input().split()))
robots = deque([0]*(2*N))
step = 0

while True:
    step += 1

    # 1) 벨트 및 로봇 회전
    belt.rotate(1)
    robots.rotate(1)
    robots[N - 1] = 0 # 로봇 내리기

    # 2) 로봇 이동
    for i in range(N - 2, -1, -1): # 가장 먼저 올린 로봇부터 이동하기 위해 역순 탐색
        if(robots[i] and not robots[i+1] and belt[i+1]>=1):
            robots[i+1] = 1
            robots[i] = 0

            belt[i+1] -=1 # 내구도 감소
    robots[N - 1] = 0 # 로봇 내리기

    # 3) 로봇 올리기
    if belt[0] >=1 and not robots[0]:
        robots[0] =1
        belt[0] -= 1 # 내구도 감소

    # 4) 내구도 0 개수 세기
    if belt.count(0) >= K:
        break

print(step)



