import sys
input = sys.stdin.readline

# 입력
N, M = map(int, input().split())
map_list = [list(map(int, input().split())) for _ in range(N)]

# 방향 (왼쪽 대각선, 아래, 오른쪽 대각선)
directions = [(-1, 1), (0, 1), (1, 1)]

# 최소 연료를 저장할 변수
min_fuel = float('inf')

# 백트래킹 함수 (현재 행, 열, 직전 방향, 누적 연료)
def dfs(row, col, prev_dir, fuel):
    global min_fuel

    # 마지막 행에 도착했을 때 최소 연료 갱신
    if row == N - 1:
        min_fuel = min(min_fuel, fuel)
        return

    # 다음 행 탐색
    for i, (dc, dr) in enumerate(directions):
        new_col = col + dc
        new_row = row + dr

        # 범위 내에 있고 직전에 수행한 방향이 아닌 경우만 탐색
        if 0 <= new_col < M and i != prev_dir:
            dfs(new_row, new_col, i, fuel + map_list[new_row][new_col])

# 첫 번째 행에서 각 모든 열을 출발점으로 설정
for start_col in range(M):
    dfs(0, start_col, -1, map_list[0][start_col])

# 최소 연료 출력
print(min_fuel)