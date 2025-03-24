import sys
import heapq
input = sys.stdin.readline

N,K = map(int,input().split())
jewels = [list(map(int,input().split())) for _ in range(N)]
bags = [int(input()) for _ in range(K)]

jewels.sort(key=lambda x:x[0]) # 보석 무게 오름차순, 무게 같으면 가격 오름차순
bags.sort() # 가방 무게 오름차순
M,result = 0,0
max_heap = [] # 최대 힙을 이용해 가치가 가장 높은 보석을 선택

for bag in bags:
    while M<N and jewels[M][0]<=bag:
        heapq.heappush(max_heap,-jewels[M][1])
        M+=1

    if max_heap:
        result += -heapq.heappop(max_heap)
print(result)