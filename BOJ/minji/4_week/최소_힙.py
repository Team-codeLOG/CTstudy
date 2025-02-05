import heapq
import sys 

input = sys.stdin.readline #시간초과 방지

min_heap = []

n = int(input())

for i in range(n):
    x = int(input())
    
    if x == 0:
        if len(min_heap) == 0:
            print(0)
        else:
            print(heapq.heappop(min_heap))
    else:
        heapq.heappush(min_heap, x)