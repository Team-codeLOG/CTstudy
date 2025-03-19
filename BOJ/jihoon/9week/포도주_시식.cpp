#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n); // �� �ܿ� ��� �������� ��
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// dp�� ���� ��ġ���� �� ������ �� �ִ� dp[i][0], ������ �� �ִ� dp[i][1]
	int dp[10000][2];
	dp[0][0] = 0;
	dp[0][1] = v[0];
	dp[1][0] = dp[0][1];
	dp[1][1] = dp[0][1] + v[1];

	for (int i = 2; i < n; i++) {
		// 1. i��° �ȸ��ô� ��� => ���� �� ���� or �ȸ���
		// 2. i��° ���ô� ��� => (���� �� �ȸ��� && ���� �� ����) or ���� �� �ȸ���

		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 2][0] + v[i - 1], dp[i - 1][0]) + v[i];
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]);

	return 0;
}