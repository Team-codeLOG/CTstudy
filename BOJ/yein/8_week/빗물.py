# 14719 빗물
        
h, w = map(int, input().split())
block = list(map(int, input().split()))

left_idx = 0
right_idx = w - 1
left_wall = block[left_idx]
right_wall = block[right_idx]

water_sum = 0

while left_idx < right_idx:
    if left_wall < right_wall:
        left_idx += 1
        if block[left_idx] < left_wall:
            # wall 업데이트 없음
            water_sum += left_wall - block[left_idx]
        else:
            # wall 업데이트 + 물 없음
            left_wall = block[left_idx]
    else:
        right_idx -= 1
        if block[right_idx] < right_wall:
            # wall 업데이트 없음
            water_sum += right_wall - block[right_idx]
        else:
            # wall 업데이트 + 물 없음
            right_wall = block[right_idx]

print(water_sum)

