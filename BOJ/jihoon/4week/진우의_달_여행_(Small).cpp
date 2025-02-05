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
