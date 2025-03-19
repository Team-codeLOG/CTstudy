# n은 보석 개수
# k는 가방 개수
# gem 배열의 각 요소는 보석 가격과 무게
# bag 배열의 각 요소는 가방 용량

# 우선순위 큐 사용!
import heapq
# 사용법 - heapq.heappush(배열, 숫자)

# sys 사용
import sys

# 입력받기
n, k = map(int, sys.stdin.readline().split())
gem = []
bag = []
for _ in range(0, n):
    heapq.heappush(gem, list(map(int, sys.stdin.readline().split())))
for _ in range(0, k):
    bag.append(int(sys.stdin.readline()))

# 작은 가방부터
bag.sort()

curr_sum = 0
temp = []
for b in bag:
    while gem and b >= gem[0][0]:
        heapq.heappush(temp, -heapq.heappop(gem)[1])
    if temp:
        curr_sum -= heapq.heappop(temp)
    elif not gem:
        break
print(curr_sum)