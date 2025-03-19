n = int(input())

classroom = [[-1] * n for _ in range(n)]
students = {}

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 인접한 친구 수, 빈 자리 수 계산 함수
# -1은 빈자리리
def check_seat(x, y, favorites):
    friend_count = 0
    blank_count = 0
    
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
            if classroom[nx][ny] == -1:
                blank_count += 1
            elif classroom[nx][ny] in favorites:
                friend_count += 1
    return friend_count, blank_count

for _ in range(n * n):
    info = list(map(int, input().split()))
    std, favorites = info[0], set(info[1:])
    students[std] = favorites

    best_pos = (-1, -1)
    max_friends = -1
    max_blank = -1

    for i in range(n):
        for j in range(n):
            if classroom[i][j] == -1:  # 빈 자리라면
                friend_count, blank_count = check_seat(i, j, favorites)
                if (friend_count > max_friends or
                   (friend_count == max_friends and blank_count > max_blank) or
                   (friend_count == max_friends and blank_count == max_blank and i < best_pos[0]) or
                   (friend_count == max_friends and blank_count == max_blank and i == best_pos[0] and j < best_pos[1])):
                    best_pos = (i, j)
                    max_friends = friend_count
                    max_blank = blank_count
    
    classroom[best_pos[0]][best_pos[1]] = std

# 만족도 계산
satisfaction = 0
score = [0, 1, 10, 100, 1000]

for i in range(n):
    for j in range(n):
        std = classroom[i][j]
        favorites = students[std]
        friend_count, _ = check_seat(i, j, favorites)
        satisfaction += score[friend_count]

print(satisfaction)
