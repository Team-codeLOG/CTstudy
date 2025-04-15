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

		// ��� ���� top���� ������
		// �ǹ��� ���� �� pop
		// �ݺ�
		while (!st.empty() && st.top() > num) {
			result++;
			st.pop();
		}
		// top���� ũ�ų� ��������� �߰�
		if (st.empty() || st.top() < num) {
			if (num > 0) st.push(num);
		}
	}

	// ��� ���� �� st�� ����ִ� ����ŭ �ǹ� ����
	while (!st.empty()) {
		result++;
		st.pop();
	}

	cout << result;

	return 0;
}