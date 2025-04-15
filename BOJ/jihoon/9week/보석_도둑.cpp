#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> info; // ������ ���Կ� ���� ����
vector<int> bag; // ���� ����

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
	// ���� -> ���� ��������
	// ���� -> ��������
	sort(info.begin(), info.end());
	sort(bag.begin(), bag.end());

	priority_queue<int> pq; // ���� �� �ִ� ������ ���� pq
	int idx = 0; // ������� Ž���� ���� ����

	// �� ���渶�� Ȯ��
	for (int i = 0; i < K; i++) {
		// i��° ���濡 ���� �� �ִ� ������ ��� pq�� �߰�
		while (idx < info.size() && bag[i] >= info[idx].first) {
			pq.push(info[idx].second);
			idx++;
		}

		// ť�� ������ ��� �ִٸ� ������ ���� ���� ���� �߰�
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result;

	return 0;
}