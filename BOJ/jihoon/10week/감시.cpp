#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> cctv;
int arr[8][8];

int result = INT_MAX;

// 상 우 하 좌
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void check0(int x, int y, int d) {
	// d 방향으로 벽이나 끝지점 도달까지 탐색
	while (1) {
		x += dx[d];
		y += dy[d];

		if (x < 0 || x >= N || y < 0 || y >= M) return;
		if (arr[x][y] == 6) return;
		if (arr[x][y] != 0) continue; // cctv인 경우
		arr[x][y] = -1; // 탐색 표시
	}
}

// idx는 cctv 배열의 인덱스값
void dfs(int idx) {
	// 모든 cctv에 대해서 탐색을 마친 경우 result 갱신
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) cnt++;
			}
		}
		result = min(result, cnt);
		return;
	}

	// cctv의 x, y좌표에 대해서
	// arr[x][y]의 값으로 어느 방향으로 갈지 판단
	int x = cctv[idx].first;
	int y = cctv[idx].second;
	int tmp[8][8] = { 0, };

	// d는 현재 가리키고 있는 방향
	for (int d = 0; d < 4; d++) {
		// 나아가는 방향에 대해서
		// arr을 업데이트할 것이므로 기존 값 담을 tmp
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				tmp[i][j] = arr[i][j];
			}
		}

		if (arr[x][y] == 1) { // 1번 cctv
			check0(x, y, d % 4);
		}
		else if (arr[x][y] == 2) { // 2번 cctv
			// 0도 180도
			check0(x, y, d % 4);
			check0(x, y, (d + 2) % 4);
		}
		else if (arr[x][y] == 3) { // 3번 cctv
			// 0도 90도
			check0(x, y, d % 4);
			check0(x, y, (d + 1) % 4);
		}
		else if (arr[x][y] == 4) { // 4번 cctv
			// 0도 90도 180도
			check0(x, y, d % 4);
			check0(x, y, (d + 1) % 4);
			check0(x, y, (d + 2) % 4);
		}
		else if (arr[x][y] == 5) { // 5번 cctv
			// 0도 90도 180도 270도
			check0(x, y, d % 4);
			check0(x, y, (d + 1) % 4);
			check0(x, y, (d + 2) % 4);
			check0(x, y, (d + 3) % 4);
		}

		// 해당 cctv의 0체크가 모두 끝나면 다음 cctv 탐색
		dfs(idx + 1);
		// 탐색 종료되면 arr 원복
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctv.push_back({ i,j });
			}
		}
	}

	dfs(0); // 0번째 cctv부터 시작
	cout << result;

	return 0;
}