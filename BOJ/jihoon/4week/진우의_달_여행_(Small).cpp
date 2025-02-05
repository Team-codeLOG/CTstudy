#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, minOil = INT_MAX;
int space[7][7];
int dx[3] = { -1, 0, 1 };

// col는 열의 위치, row는 행의 위치, sum은 현재까지의 연료 소비량, dir은 현재 이동 방향
void dfs(int col, int row, int sum, int dir) {
    sum += space[row][col];  // 현재 위치 연료 소비량 추가

    // 마지막 행에 도착한 경우
    if (row == N - 1) {
        minOil = min(minOil, sum);
        return;
    }

    // 3가지 방향으로 이동
    for (int i = 0; i < 3; i++) {
        if (i == dir) continue;

        int nx = col + dx[i];

        // 열을 벗어나는 경우 패스
        if (nx < 0 || nx >= M) continue;

        dfs(nx, row + 1, sum, i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> space[i][j];

    // 각 열에서 출발할 수 있도록 설정
    for (int i = 0; i < M; i++) {
        // 첫방향은 -1로 무의미한 방향 설정
        dfs(i, 0, 0, -1);
    }

    cout << minOil << "\n";

    return 0;
}
