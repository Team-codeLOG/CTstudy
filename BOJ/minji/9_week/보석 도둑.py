import sys
import heapq

input = sys.stdin.readline

# 보석의 개수 n, 가방의 개수 k
n, k = map(int, input().split())

# 보석의 정보 - 무게 m, 가격 v
jewel_list = [list(map(int, input().split())) for _ in range(n)]
#   jewel_list.sort(key=lambda x: (x[1], x[0]), reverse=True) 
jewel_list.sort()  # 무게 기준으로 오름차순 정렬


# 각 가방에 담을 수 있는 최대 무게 c
bag_list = [int(input()) for _ in range(k)]
bag_list.sort()

# 가장 비싼 보석을 선택해야 하기 때문에 최대 힙 사용
max_heap = []
max_value = 0
jewel_index = 0

# 각 가방에 대해 반복
for bag in bag_list:
    # 현재 가방이 담을 수 있는 보석들을 힙에 추가함

    while jewel_index < n and jewel_list[jewel_index][0] <= bag: # 보석의 무게가 가방의 무게보다 작거나 같으면
        # 보석을 힙에 추가, pyhton 에서 heap은 기본적으로 최소 힙이기 때문에 음수로 변경하여 넣음음
        heapq.heappush(max_heap, -jewel_list[jewel_index][1])
        jewel_index += 1

    # 힙에 넣을 수 있는 보석들이 저장된 상태태
    if max_heap:
        # 힙에서 가장 비싼 보석을 꺼내서 max_value에 더함
        # 가격을 다시 음수로 바꾸어 더함
        max_value += -heapq.heappop(max_heap)

# 모든 가방에 대해 최대 가치 합을 구함
print(max_value)


