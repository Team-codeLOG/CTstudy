#include <iostream>
#include <vector>

using namespace std;

int T, N;

// 최대 이익을 계산
long long maxMoney(vector<int> stock) {
    // 뒤에서부터 시작하여 max와 자신의 비교하여 max 갱신
    // max - 자신 값을 결과값에 증감
    // 이때 max는 주식을 파는 날의 최댓값임

    long long result = 0; // 총 이익
    int maxStock = 0; // 주식 최댓값
    for (int i = N - 1; i >= 0; i--) {
        maxStock = max(maxStock, stock[i]);
        result += maxStock - stock[i]; // 이익
    }
    return result;
}

// 각 테스트케이스마다 계산 및 출력
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