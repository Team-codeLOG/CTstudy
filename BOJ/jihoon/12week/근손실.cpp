#include <bits/stdc++.h>

using namespace std;

int N, K;
int kit[8];
bool visited[8];
int weight = 500;
int caseCnt = 0;

void backtracking(int cnt) {
	if (cnt == N - 1) {
		if (weight >= 500) caseCnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] || weight - K + kit[i] < 500) continue;

		visited[i] = true;
		weight = weight - K + kit[i];
		backtracking(cnt + 1);
		visited[i] = false;
		weight = weight + K - kit[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> kit[i];
	}

	backtracking(0);

	cout << caseCnt;

	return 0;
}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		shortKey(str);
	}

	return 0;
}