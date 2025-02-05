/* DFS 풀이 */

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


/* DP 풀이 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int space[7][7];
long long dp[7][7][3]; // 각 위치까지의 최소 연료량을 담는 dp -> INT_MAX + 연료 연산을 오버 플로우 방지로 long long 타입
int dx[3] = { -1, 0, 1 };

// dp 채우기
void fill_dp() {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dir = 0; dir < 3; dir++) { // 진행할 다음 방향
                int prev_col = j - dx[dir]; // 이전 열(이동 전)
                if (prev_col < 0 || prev_col >= M) continue;

                // 이전 행에서 진행한 방향과 다른 방향으로 전진
                for (int prev_dir = 0; prev_dir < 3; prev_dir++) {
                    if (prev_dir == dir) continue; // 이전 행에서 진행한 방향과 현재 위치에서 진행할 방향이 같으면 안됨

                    // 진행할 다음 방향 = min(진행할 다음 방향에 기록된 누적 연료, 이동 전 위치에서의 prev_dir 진행 방향의 누적 연료 + 이동할 위치에서 필요한 연료)
                    dp[i][j][dir] = min(dp[i][j][dir], dp[i - 1][prev_col][prev_dir] + space[i][j]);
                }
            }
        }
    }
}

// dp 초기값 설정
void dp_init() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++) {
            dp[0][i][j] = space[0][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    // 연료 입력 및 dp 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> space[i][j];
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INT_MAX; // 최댓값으로 기본 설정
            }
        }
    }

    dp_init();
    fill_dp();

    // 최소 연료 출력
    long long minOil = INT_MAX;
    for (int j = 0; j < M; j++) {
        for (int k = 0; k < 3; k++) {
            minOil = min(minOil, dp[N - 1][j][k]);
        }
    }

    cout << minOil << "\n";

    return 0;
}
