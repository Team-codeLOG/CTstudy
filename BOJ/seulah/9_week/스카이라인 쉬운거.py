import sys
input = sys.stdin.readline

N = int(input())
skylines = [list(map(int,input().split())) for _ in range(N)]
skylines.append([0,0])

building = 0
stack = []

for x,y in skylines:
    while stack and stack[-1] > y: # 다음 값이 더 작을 경우 => 건물 종료
        stack.pop()
        building +=1
    if not stack or stack[-1] < y: #스택이 비어있거나 다음 값이 더 클 경우
        stack.append(y) #건물 시작 -> 스택에 삽입


print(building)
