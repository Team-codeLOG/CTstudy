# n = int(input())
# sky_line = [list(map(input().split())) for _ in range(n)]

# sky_line.reverse()

# cnt = 0

# # def count_X_clusters(arr):
# #     count = 0  # 덩어리 개수
# #     in_cluster = False 
    
# #     for elem in arr:
# #         if elem == 'X' and not in_cluster:
# #             count += 1 
# #             in_cluster = True 
# #         elif elem != 'X':
# #             in_cluster = False 
    
# #     return count

# # for i in range(n):
# #     sky_line

# def count_X_clusters(arrays):
#     count = 0  # 덩어리 개수
#     previous_clusters = set()  # 이전 배열에서 찾은 덩어리들 (중복 방지)
    
#     for arr in arrays:
#         in_cluster = False  # 현재 배열에서 덩어리 내부에 있는지 여부
#         current_clusters = set()  # 현재 배열에서 찾은 덩어리들
        
#         for i, elem in enumerate(arr):
#             if elem == 'X' and not in_cluster:  # 새로운 덩어리 시작
#                 # 덩어리의 시작 인덱스 저장
#                 current_clusters.add(i)
#                 in_cluster = True  # 덩어리 안에 있다고 설정
#             elif elem != 'X':  # 'X'가 아닌 값 만나면 덩어리 끝
#                 in_cluster = False
        
#         # 현재 배열에서 찾은 덩어리 중 이전 배열에서 찾은 덩어리와 중복되지 않는 것만 카운트
#         for cluster in current_clusters:
#             if cluster not in previous_clusters:
#                 count += 1
#                 previous_clusters.add(cluster)  # 중복 방지를 위해 기록
        
#     return count

# print(count_X_clusters(sky_line))

def count_skyline_clusters(n, points):
    count = 0  # 덩어리 개수
    previous_clusters = set()  # 이전에 나온 덩어리들을 저장할 set
    
    # 첫 번째 점은 무조건 x=1로 시작
    prev_y = points[0][1]  # 첫 번째 점의 y 값을 기록
    prev_x = points[0][0]  # 첫 번째 점의 x 값을 기록
    previous_clusters.add((prev_y, prev_x))  # 첫 번째 점의 덩어리를 기록
    count += 1  # 첫 번째 덩어리는 1로 시작
    
    for i in range(1, n):
        x, y = points[i]
        
        if y != prev_y:  # y 값이 이전 값과 다르면 새로운 덩어리 시작
            if (y, x) not in previous_clusters:
                count += 1
                previous_clusters.add((y, x))  # 새로운 덩어리 추가
        
        prev_y = y  # 이전 y 값 갱신
        prev_x = x  # 이전 x 값 갱신
    
    return count

# 입력 받기
n = int(input())  # n개의 좌표 입력
points = [tuple(map(int, input().split())) for _ in range(n)]  # 좌표 입력

# 연속된 'X' 덩어리 개수 출력
print(count_skyline_clusters(n, points))
