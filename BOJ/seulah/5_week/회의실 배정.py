import sys
input = sys.stdin.readline

N = int(input())
schedules = [list(map(int,input().split())) for _ in range(N)]

schedules.sort(key=lambda x: (x[1],x[0]))
cnt =0
end_time =0

for start,end in schedules:
    if start >= end_time:
        cnt+=1
        end_time = end
print(cnt)