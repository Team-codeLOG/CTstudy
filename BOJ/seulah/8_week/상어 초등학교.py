n = int(input())
students = [list(map(int, input().split())) for _ in range(n**2)]

data = [[0] * n for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

for student in students:
    max_prefer, max_empty = -1,-1
    x,y = 0,0
    for i in range(n):
        for j in range(n):
            # 빈자리가 있다면
            if data[i][j] == 0:
                prefer, empty = 0, 0

                # 상하좌우 확인
                for k in range(4):
                    nx = i + dx[k]
                    ny = j + dy[k]

                    if 0 <= nx < n and 0 <= ny < n:
                        # 좋아하는 학생이 주위에 있다면
                        if data[nx][ny] in student[1:]:
                            prefer += 1
                        # 빈자리가 있다면
                        if data[nx][ny] == 0:
                            empty += 1

                # 조건 1) 좋아하는 학생이 가장 많이 인접해있는 곳
                if prefer > max_prefer:
                    max_prefer = prefer
                    max_empty = empty  # 빈자리 개수도 갱신
                    x, y = i, j  # 최적의 자리 갱신

                # 조건 2) 1을 만족하는 가장 많은 인접해있는 곳도 여러 개면
                elif max_prefer == prefer:
                    if empty > max_empty:
                        max_empty = empty  # 빈자리가 가장 많은 곳 선택
                        x, y = i, j  # 최적의 자리 갱신
                    # 조건 3) 2를 만족하는 가장 많은 빈자리도 여러 개면
                    elif max_empty == empty:
                        if i < x:  # 행이 더 작은 곳을 선택
                            x , y = i, j
                        elif i == x and j < y:  # 행이 같다면 열이 더 작은 곳을 선택
                            x, y = i, j

    data[x][y] = student[0]  # 최적의 자리에 학생 배치

# 만족도 계산
satisfaction = 0
score = {0: 0, 1: 1, 2: 10, 3: 100, 4: 1000}
students.sort() #학생 번호를 기준으로 정렬

for i in range(n):
    for j in range(n):
        student_num = data[i][j]
        prefer = 0
        for k in range(4):
            nx = dx[k]+i
            ny = dy[k]+j
            if 0 <= nx < n and 0 <= ny < n:
                # 좋아하는 학생이 주위에 있다면
                if data[nx][ny] in students[student_num-1][1:]:
                    prefer += 1
        satisfaction += score[prefer]  # 최종 만족도

print(satisfaction)




