#include <iostream>
#include <vector>

using namespace std;

int N;
int cookie[5]; // ��Ű�� ���� ��, ������ ��, �㸮, ���� �ٸ�, ������ �ٸ��� ���̸� ���� �迭
vector<vector<int>> board; // ��Ű�� ��ġ����
pair<int, int> heart;

// ��Ű ���� ���ϱ�
void calculate() {
    int starty = heart.first; // i
    int startx = heart.second; // j

    // ���� ��
    int cnt = 0;
    while (startx - cnt - 1 >= 0 && board[starty][startx - cnt - 1] == 1) cnt++;
    cookie[0] = cnt;

    // ������ ��
    cnt = 0;
    while (startx + cnt + 1 < N && board[starty][startx + cnt + 1] == 1) cnt++;
    cookie[1] = cnt;

    // �㸮
    cnt = 0;
    while (starty + cnt + 1 < N && board[starty + cnt + 1][startx] == 1) cnt++;
    cookie[2] = cnt;

    // �ٸ� ���� ���� ����
    starty += cookie[2];

    // ���� �ٸ�
    cnt = 0;
    while (starty + cnt + 1 < N && board[starty + cnt + 1][startx - 1] == 1) cnt++;
    cookie[3] = cnt;

    // ������ �ٸ�
    cnt = 0;
    while (starty + cnt + 1 < N && board[starty + cnt + 1][startx + 1] == 1) cnt++;
    cookie[4] = cnt;
}

// ��Ű ���� �Է�
void input() {
    cin >> N;
    board.resize(N, vector<int>(N, 0));
    bool headChk = false;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == '*') {
                if (!headChk) {
                    heart.first = i + 1; // ���� y��ǥ
                    heart.second = j; // ���� x��ǥ
                    headChk = true;
                }
                board[i][j] = 1; // ��Ű�� �ִ� ���� 1, �ƴϸ� 0
            }
        }
    }
}

// ��Ű ���� ���
void output() {
    cout << heart.first + 1 << " " << heart.second + 1 << "\n";
    cout << cookie[0] << " " << cookie[1] << " " << cookie[2] << " " << cookie[3] << " " << cookie[4] << "\n";
}

void solve() {
    input();
    calculate();
    output();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}