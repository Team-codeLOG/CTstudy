import sys
input = sys.stdin.readline

n = int(input())

time_list = []

for i in range(n):
    time_list.append(list(map(int, input().split())))

#끝나는 시간을 기준으로 정렬
time_list.sort(key=lambda x: (x[1], x[0]))

count = 0 
last_end = 0  

#회의가 겹치지 않으면 선택
for start, end in time_list:
    if start >= last_end:
        count += 1
        last_end = end 
print(count)