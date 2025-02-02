#include <iostream>
#include <vector>

using namespace std;

int T, N;

// �ִ� ������ ���
long long maxMoney(vector<int> stock) {
    // �ڿ������� �����Ͽ� max�� �ڽ��� ���Ͽ� max ����
    // max - �ڽ� ���� ������� ����
    // �̶� max�� �ֽ��� �Ĵ� ���� �ִ���

    long long result = 0; // �� ����
    int maxStock = 0; // �ֽ� �ִ�
    for (int i = N - 1; i >= 0; i--) {
        maxStock = max(maxStock, stock[i]);
        result += maxStock - stock[i]; // ����
    }
    return result;
}

// �� �׽�Ʈ���̽����� ��� �� ���
void solve() {
    vector<int> stock(N);
    for (int i = 0; i < N; i++) {
        cin >> stock[i];
    }
    long long result = maxMoney(stock);
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        solve();
    }

    return 0;
}