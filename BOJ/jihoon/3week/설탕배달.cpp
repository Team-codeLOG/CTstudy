#include <iostream>

using namespace std;

int N;

// �׸��� �˰���
// 5Ű�� ������ �ִ��� ���鼭 3Ű�� �������� ������ �������� ��츦 �ľ�
int solve() {
    int result = 0;
    int x, y, max = 10000;

    for (int i = 0; i * 5 <= N; i++) {
        x = i * 5; // 5Ű�� ���� �� Ű�μ�
        y = N - x; // 5Ű�� ���� ������ Ű�μ�
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