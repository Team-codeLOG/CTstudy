#include <bits/stdc++.h>

using namespace std;

int N, D;
int dp[10001];
vector<pair<pair<int, int>, int>> v;
queue<pair<pair<int, int>, int>> dis; // ������ ť

// ������ �������� �������� �������� ����
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.first.first < b.first.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		v.push_back({ {s,e},d });
	}

	// ���� �� ������ ť�� ���
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		dis.push(v[i]);
	}

	// ���ۺ��� D���� �ݺ�
	for (int i = 0; i <= D; i++) {
		// ���� ��ġ �� ����
		if (i != 0) {
			if (dp[i] == 0) dp[i] = dp[i - 1] + 1;
			else dp[i] = min(dp[i], dp[i - 1] + 1);
		}

		// ������ �� �� ����
		int s = -1, e = -1, d = -1;
		while (!dis.empty() && dis.front().first.first == i) {
			// ������ ���� ���� �Ÿ��� �ʰ��ߴٸ� �н�
			if (dis.front().first.second > D) {
				dis.pop();
				continue;
			}

			s = dis.front().first.first;
			e = dis.front().first.second;
			d = dis.front().second;
			dis.pop();

			// e�� dp ����

			// �ʱⰪ�̶��
			if (dp[e] == 0) dp[e] = dp[i] + d;
			else { // �̹� ���� �ִٸ�
				dp[e] = min(dp[e], dp[i] + d);
			}
		}
	}

	cout << dp[D];

	return 0;
}