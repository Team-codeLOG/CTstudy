#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> roomTime;

// ���������� ȸ�ǽ� ���� ����
int roomCnt() {
	int count = 0, endTime = 0;
	for (int i = 0; i < N; i++) {
		if (endTime <= roomTime[i].first) {
			count++;
			endTime = roomTime[i].second;
		}
	}
	return count;
}

// �� �ð� �������� ���� -> ���ð� ���ٸ� ���� �ð� �������� ����
bool cmp(pair<int, int> t1, pair<int, int> t2) {
	if (t1.second == t2.second) return t1.first < t2.first;
	return t1.second < t2.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		roomTime.push_back({ s,e });
	}

	sort(roomTime.begin(), roomTime.end(), cmp);

	cout << roomCnt();

	return 0;
}