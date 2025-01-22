#include <iostream>
#include <vector>

using namespace std;

int N;
int cookie[5]; // 쿠키의 왼쪽 팔, 오른쪽 팔, 허리, 왼쪽 다리, 오른쪽 다리의 길이를 담은 배열
vector<vector<int>> board; // 쿠키의 위치정보
pair<int, int> heart;

// 쿠키 길이 구하기
void calculate() {
    int starty = heart.first; // i
    int startx = heart.second; // j

    // 왼쪽 팔
    int cnt = 0;
    while (startx - cnt - 1 >= 0 && board[starty][startx - cnt - 1] == 1) cnt++;
    cookie[0] = cnt;

    // 오른쪽 팔
    cnt = 0;
    while (startx + cnt + 1 < N && board[starty][startx + cnt + 1] == 1) cnt++;
    cookie[1] = cnt;

    // 허리
    cnt = 0;
    while (starty + cnt + 1 < N && board[starty + cnt + 1][startx] == 1) cnt++;
    cookie[2] = cnt;

    // 다리 시작 지점 갱신
    starty += cookie[2];

    // 왼쪽 다리
    cnt = 0;
    while (starty + cnt + 1 < N && board[starty + cnt + 1][startx - 1] == 1) cnt++;
    cookie[3] = cnt;

    // 오른쪽 다리
    cnt = 0;
    while (starty + cnt + 1 < N && board[starty + cnt + 1][startx + 1] == 1) cnt++;
    cookie[4] = cnt;
}

// 쿠키 정보 입력
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
                    heart.first = i + 1; // 심장 y좌표
                    heart.second = j; // 심장 x좌표
                    headChk = true;
                }
                board[i][j] = 1; // 쿠키가 있는 곳은 1, 아니면 0
            }
        }
    }
}

// 쿠키 정보 출력
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