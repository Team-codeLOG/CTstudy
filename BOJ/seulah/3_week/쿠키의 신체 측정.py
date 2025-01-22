N = int(input())
cookie = [input() for _ in range(N)]

# 심장
for i in range(N):
    for j in range(N):
        if cookie[i][j] == '*':
            heart_x, heart_y = i + 1, j
            break
    else:
        continue
    break

# 팔
left_part = cookie[heart_x][:heart_y]  # 심장 왼쪽 부분
right_part = cookie[heart_x][heart_y + 1:]  # 심장 오른쪽 부분

left_arm = left_part.count('*')  # 왼쪽 팔 길이
right_arm = right_part.count('*')  # 오른쪽 팔 길이

# 허리
waist = 0
for i in range(heart_x + 1, N):  # 심장 아래로 탐색
    if cookie[i][heart_y] == '*':
        waist += 1
    else:
        break

# 다리
left_leg = 0
right_leg = 0
for i in range(heart_x + waist + 1, N):  # 허리 끝 아래로 탐색
    if cookie[i][heart_y - 1] == '*':  # 왼쪽 다리
        left_leg += 1
    if cookie[i][heart_y + 1] == '*':  # 오른쪽 다리
        right_leg += 1

# 출력
print(heart_x + 1, heart_y + 1)
print(left_arm, right_arm, waist, left_leg, right_leg)
