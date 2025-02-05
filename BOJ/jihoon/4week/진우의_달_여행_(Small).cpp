/* DFS Ǯ�� */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, minOil = INT_MAX;
int space[7][7];
int dx[3] = { -1, 0, 1 };

// col�� ���� ��ġ, row�� ���� ��ġ, sum�� ��������� ���� �Һ�, dir�� ���� �̵� ����
void dfs(int col, int row, int sum, int dir) {
    sum += space[row][col];  // ���� ��ġ ���� �Һ� �߰�

    // ������ �࿡ ������ ���
    if (row == N - 1) {
        minOil = min(minOil, sum);
        return;
    }

    // 3���� �������� �̵�
    for (int i = 0; i < 3; i++) {
        if (i == dir) continue;

        int nx = col + dx[i];

        // ���� ����� ��� �н�
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

    // �� ������ ����� �� �ֵ��� ����
    for (int i = 0; i < M; i++) {
        // ù������ -1�� ���ǹ��� ���� ����
        dfs(i, 0, 0, -1);
    }

    cout << minOil << "\n";

    return 0;
}


/* DP Ǯ�� */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M;
int space[7][7];
long long dp[7][7][3]; // �� ��ġ������ �ּ� ���ᷮ�� ��� dp -> INT_MAX + ���� ������ ���� �÷ο� ������ long long Ÿ��
int dx[3] = { -1, 0, 1 };

// dp ä���
void fill_dp() {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dir = 0; dir < 3; dir++) { // ������ ���� ����
                int prev_col = j - dx[dir]; // ���� ��(�̵� ��)
                if (prev_col < 0 || prev_col >= M) continue;

                // ���� �࿡�� ������ ����� �ٸ� �������� ����
                for (int prev_dir = 0; prev_dir < 3; prev_dir++) {
                    if (prev_dir == dir) continue; // ���� �࿡�� ������ ����� ���� ��ġ���� ������ ������ ������ �ȵ�

                    // ������ ���� ���� = min(������ ���� ���⿡ ��ϵ� ���� ����, �̵� �� ��ġ������ prev_dir ���� ������ ���� ���� + �̵��� ��ġ���� �ʿ��� ����)
                    dp[i][j][dir] = min(dp[i][j][dir], dp[i - 1][prev_col][prev_dir] + space[i][j]);
                }
            }
        }
    }
}

// dp �ʱⰪ ����
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
    // ���� �Է� �� dp �ʱ�ȭ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> space[i][j];
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INT_MAX; // �ִ����� �⺻ ����
            }
        }
    }

    dp_init();
    fill_dp();

    // �ּ� ���� ���
    long long minOil = INT_MAX;
    for (int j = 0; j < M; j++) {
        for (int k = 0; k < 3; k++) {
            minOil = min(minOil, dp[N - 1][j][k]);
        }
    }

    cout << minOil << "\n";

    return 0;
}
