#include <bits/stdc++.h>

using namespace std;

int N, L, R;
int world[50][50];
bool visited[50][50];

int day = 0;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool bfs(int x, int y) {
	bool check = false;
	int sum = world[x][y];

	queue<pair<int, int>> group; // 연합
	queue<pair<int, int>> q;

	q.push({ x,y });
	group.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

			if (abs(world[xpos][ypos] - world[nx][ny]) >= L && abs(world[xpos][ypos] - world[nx][ny]) <= R) {
				q.push({ nx, ny });
				group.push({ nx,ny });
				sum += world[nx][ny];
				visited[nx][ny] = true;
				check = true; // 연합 생성
			}
		}
	}

	int avg = sum / group.size();
	while (!group.empty()) {
		world[group.front().first][group.front().second] = avg;
		group.pop();
	}

	return check;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> world[i][j];
		}
	}

	bool check = true;
	while (check) {
		check = false;
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 연합이 형성되면 check를 true로
				if (!visited[i][j] && bfs(i, j)) check = true;
			}
		}
		if (check) day++;
	}

	cout << day;

	return 0;
}