import sys
input = sys.stdin.readline

# n: n개의 얼음 양동이들
# x: 양동이 좌표
# g: 각 양동이에는 g개의 얼음 들어있음
# k: 앨버트가 자리를 잡으면 좌우로 k만큼 떨어진 양동이 접근 가능

n, k = map(int, input().split())

ice = [0] * 1000001

for _ in range(n):
    g, x = map(int, input().split())
    ice[x] = g

window_size = 2 * k + 1

current_sum = sum(ice[:window_size])
max_ice = current_sum

for i in range(window_size, 1000001):
    current_sum += (ice[i] - ice[i-window_size]) 
    max_ice = max(max_ice, current_sum)

print(max_ice)
