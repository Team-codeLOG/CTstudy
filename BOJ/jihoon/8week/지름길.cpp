#include <bits/stdc++.h>

using namespace std;

int N, D;
int dp[10001];
vector<pair<pair<int, int>, int>> v;
queue<pair<pair<int, int>, int>> dis; // 지름길 큐

// 지름길 시작점을 기준으로 오름차순 정렬
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

	// 정렬 후 지름길 큐에 담기
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		dis.push(v[i]);
	}

	// 시작부터 D까지 반복
	for (int i = 0; i <= D; i++) {
		// 현재 위치 값 갱신
		if (i != 0) {
			if (dp[i] == 0) dp[i] = dp[i - 1] + 1;
			else dp[i] = min(dp[i], dp[i - 1] + 1);
		}

		// 지름길 끝 값 갱신
		int s = -1, e = -1, d = -1;
		while (!dis.empty() && dis.front().first.first == i) {
			// 지름길 끝이 최종 거리를 초과했다면 패스
			if (dis.front().first.second > D) {
				dis.pop();
				continue;
			}

			s = dis.front().first.first;
			e = dis.front().first.second;
			d = dis.front().second;
			dis.pop();

			// e의 dp 갱신

			// 초기값이라면
			if (dp[e] == 0) dp[e] = dp[i] + d;
			else { // 이미 값이 있다면
				dp[e] = min(dp[e], dp[i] + d);
			}
		}
	}

	cout << dp[D];

	return 0;
}