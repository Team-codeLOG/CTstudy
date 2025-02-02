#include <iostream>

using namespace std;

int N;

// 그리디 알고리즘
// 5키로 봉지를 최대한 쓰면서 3키로 봉지수로 나누어 떨어지는 경우를 파악
int solve() {
    int result = 0;
    int x, y, max = 10000;

    for (int i = 0; i * 5 <= N; i++) {
        x = i * 5; // 5키로 봉지 수 키로수
        y = N - x; // 5키로 봉지 제외한 키로수
        if (y % 3 == 0) {
            if (max > i + y / 3) {
                max = i + y / 3;
            }
        }
    }

    if (max == 10000) return -1;
    else return max;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cout << solve();

    return 0;
}