#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> info; // 보석의 무게와 가격 정보
vector<int> bag; // 가방 정보

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		info.push_back({ m, v });
	}
	for (int i = 0; i < K; i++) {
		int c;
		cin >> c;
		bag.push_back(c);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long result = 0;

	input();
	// 보석 -> 무게 오름차순
	// 가방 -> 오름차순
	sort(info.begin(), info.end());
	sort(bag.begin(), bag.end());

	priority_queue<int> pq; // 담을 수 있는 보석을 담을 pq
	int idx = 0; // 현재까지 탐색한 보석 개수

	// 각 가방마다 확인
	for (int i = 0; i < K; i++) {
		// i번째 가방에 담을 수 있는 보석을 모두 pq에 추가
		while (idx < info.size() && bag[i] >= info[idx].first) {
			pq.push(info[idx].second);
			idx++;
		}

		// 큐에 보석이 담겨 있다면 가격이 가장 높은 보석 추가
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;

	return 0;
}