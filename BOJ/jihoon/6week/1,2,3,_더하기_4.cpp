#include <bits/stdc++.h>

using namespace std;

int dp[10001][4];

void solve(int n) {
    dp[1][1] = 1; // 1

    dp[2][1] = 1; // 1+1
    dp[2][2] = 1; // 2

    dp[3][1] = 1; // 1+1+1
    dp[3][2] = 1; // 2+1
    dp[3][3] = 1; // 3

    dp[4][1] = 1; // 1+1+1+1 // 무조건 1개
    dp[4][2] = 2; // (2)+2, (2)+1+1 => 2는 무조건 들어가야함 => 4-2인 dp[2][1] + dp[2][2]의 값
    dp[4][3] = 1; // 3+1 => dp[4-3][1] + dp[1][2] + dp[1][3]의 값

    // dp[n][1] = 1
    // dp[n][2] = dp[n-2][1] + dp[n-2][2]
    // dp[n][3] = dp[n-3][1] + dp[n-3][2] + dp[n-3][3]

    for (int i = 4; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    solve(10000);
    for (int testcase = 0; testcase < T; testcase++) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }

    return 0;
}