#include <bits/stdc++.h>

using namespace std;

int n, result;
vector<pair<int, int>> v;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int num = v[i].second;

		// 담는 수가 top보다 작으면
		// 건물수 증가 후 pop
		// 반복
		while (!st.empty() && st.top() > num) {
			result++;
			st.pop();
		}
		// top보다 크거나 비어있으면 추가
		if (st.empty() || st.top() < num) {
			if (num > 0) st.push(num);
		}
	}

	// 모두 끝난 후 st에 들어있는 수만큼 건물 증가
	while (!st.empty()) {
		result++;
		st.pop();
	}

	cout << result;

	return 0;
}