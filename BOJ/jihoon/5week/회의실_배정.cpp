#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> roomTime;

// 참여가능한 회의실 개수 세기
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

// 끝 시간 오름차순 정렬 -> 끝시간 같다면 시작 시간 오름차순 정렬
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