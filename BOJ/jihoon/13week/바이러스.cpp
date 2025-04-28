#include <bits/stdc++.h>

using namespace std;

int N;
int con;
int network[101][101];
bool visited[101];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> con;
	for (int i = 0; i < con; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		network[n1][n2] = 1;
		network[n2][n1] = 1;
	}

	queue<int> q;
	visited[1] = true;
	for (int i = 2; i <= N; i++) {
		if (network[1][i] == 1) {
			q.push(i);
			visited[i] = true;
			cnt++;
		}
	}

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (i == n) continue;

			if (network[n][i] == 1 && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}