#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N;
vector<pair<int, vector<int>>> stu;
int board[21][21]; // 교실 좌석

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b); // 좋아하는 좌석이 많은 순
	else if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // 빈자리가 많은 순
	else if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b); // 행이 작은 순
	return get<3>(a) < get<3>(b); // 열이 작은 순
}

// 학생 좌석 선택
void select() {
	// 첫번째 학생은 (2,2) 고정
	board[2][2] = stu[0].first;

	// 각 학생을 돌며, 1 -> 2 -> 3 의 조건을 만족하는대로 좌석 배치
	for (int i = 1; i < stu.size(); i++) {
		vector<tuple<int, int, int, int>> xy; // (좋아하는 학생 수, 빈칸 수, 행, 열)
		// 1. 인접칸에 좋아하는 학생이 가장 많은 곳
		// 해당 조건의 최댓값은 4 -> 4부터 0까지 탐색하는데, 값이 나오는 순간
		// 조건 2로 이동

		unordered_map<int, int> m; // 좋아하는 학생
		for (int j = 0; j < 4; j++) m.insert({ stu[i].second[j], 1 });

		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				// 학생이 있다면 패스
				if (board[x][y] != 0) continue;

				int cnt = 0; // 좋아하는 학생 수
				int emptyCnt = 0; // 주변 빈칸

				// 한칸씩만 탐색하면 되므로 그냥 탐색
				// 상
				if (x - 1 >= 1) {
					if (m.find(board[x - 1][y]) != m.end()) cnt++;
					if (board[x - 1][y] == 0) emptyCnt++;
				}
				// 하
				if (x + 1 <= N) {
					if (m.find(board[x + 1][y]) != m.end()) cnt++;
					if (board[x + 1][y] == 0) emptyCnt++;
				}
				// 좌
				if (y - 1 >= 1) {
					if (m.find(board[x][y - 1]) != m.end()) cnt++;
					if (board[x][y - 1] == 0) emptyCnt++;
				}
				// 우
				if (y + 1 <= N) {
					if (m.find(board[x][y + 1]) != m.end()) cnt++;
					if (board[x][y + 1] == 0) emptyCnt++;
				}

				xy.push_back({ cnt, emptyCnt, x, y });
			}
		}

		// 조건 1(좋아하는 학생 수), 2(주변 빈칸), 3(행 -> 열 최소)에 맞는 학생 자리 배치
		sort(xy.begin(), xy.end(), cmp);
		board[get<2>(xy[0])][get<3>(xy[0])] = stu[i].first;
	}
}

long long satisfy() {
	long long result = 0;

	// 각 위치를 돌며 인접한 좋아하는 학생수 개수 세고 값 추가
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			// 해당 위치의 학생의 좋아하는 학생 map
			unordered_map<int, int> m; // 좋아하는 학생
			for (int i = 0; i < N * N; i++) {
				if (stu[i].first == board[x][y]) {
					for (int j = 0; j < 4; j++) m.insert({ stu[i].second[j], 1 });
					break;
				}
			}

			int cnt = 0; // 좋아하는 학생 수

			// 한칸씩만 탐색하면 되므로 그냥 탐색
			// 상
			if (x - 1 >= 1) {
				if (m.find(board[x - 1][y]) != m.end()) cnt++;
			}
			// 하
			if (x + 1 <= N) {
				if (m.find(board[x + 1][y]) != m.end()) cnt++;
			}
			// 좌
			if (y - 1 >= 1) {
				if (m.find(board[x][y - 1]) != m.end()) cnt++;
			}
			// 우
			if (y + 1 <= N) {
				if (m.find(board[x][y + 1]) != m.end()) cnt++;
			}

			// 10의 cnt-1 제곱만큼 더하기
			result += (long long)pow(10, cnt - 1);
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	// 학생 정보 입력
	int n;
	for (int i = 0; i < N * N; i++) {
		cin >> n;
		vector<int> tmp;
		int t;
		for (int j = 0; j < 4; j++) {
			cin >> t;
			tmp.push_back(t);
		}
		stu.push_back({ n, tmp });
	}

	select();

	// 만족도 구하기
	cout << satisfy();

	return 0;
}