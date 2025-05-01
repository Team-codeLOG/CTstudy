#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Fish {
	int num;
	int dir;
	pair<int, int> xy;
};

struct Shark {
	int dir;
	pair<int, int> xy;
	int point;
};

// 0 없음 1 상, 2 좌상, 3 좌, 4 하좌, 5 하, 6 우하, 7 우 8 우상
const int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int maxPoint = 0;

// 상어 이동 방향에 물고기가 있는지 체크
queue<pair<int, int>> isMoveShark(Shark shark, Fish fish[17], vector<vector<int>> board) {
	queue<pair<int, int>> sharkQ;

	int check = false;
	int nx = shark.xy.first;
	int ny = shark.xy.second;

	while (1) {
		nx += dx[shark.dir];
		ny += dy[shark.dir];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;

		if (board[nx][ny] > 0 && fish[board[nx][ny]].num > 0) {
			sharkQ.push({ nx,ny });
		}
	}

	return sharkQ;
}

void moveFish(Fish fish[17], vector<vector<int>>& board) {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].num <= 0) continue;

		int dir = fish[i].dir; // 현재 물고기의 방향
		pair<int, int> xy = fish[i].xy; // 현재 물고기의 좌표

		// 물고기의 이동 좌표 => 이동 가능 시 이동 후 break
		for (int j = 0; j < 8; j++) {
			int ndir = (dir + j - 1) % 8 + 1;
			int nx = xy.first + dx[ndir];
			int ny = xy.second + dy[ndir];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || board[nx][ny] == -1) continue;

			// j 방향으로 물고기 이동
			// 교환 형식 | 물고기 - 물고기 or 빈칸 - 물고기

			// 물고기 값 변경
			fish[board[nx][ny]].xy = fish[i].xy;
			fish[i].xy = { nx, ny };
			fish[i].dir = ndir;

			// 보드 위치 변경
			swap(board[xy.first][xy.second], board[nx][ny]);

			break;
		}
	}
}

// 백트래킹하며 상어가 탐색하지 못할 때 maxPoint 갱신
void dfs(Shark shark, Fish fish[17], vector<vector<int>>& board, int point) {
	// 물고기 이동 후 => 상어 먹방 => 먹방 못하면 maxPoint 갱신

	// 물고기 이동
	moveFish(fish, board);

	// sharkQ 초기화
	queue<pair<int, int>> sharkQ = isMoveShark(shark, fish, board);

	// 상어 먹방 가능 여부
	if (!sharkQ.empty()) {
		// sharkQ에는 이동 가능한 좌표가 들어 있음
		while (!sharkQ.empty()) {
			Fish newFish[17];
			copy(fish, fish + 17, newFish);
			vector<vector<int>> newBoard = board;

			pair<int, int> xy = sharkQ.front();
			sharkQ.pop();

			int moveNum = newBoard[xy.first][xy.second];
			Shark newShark = { newFish[moveNum].dir, newFish[moveNum].xy, shark.point + newFish[moveNum].num };
			newFish[moveNum] = { 0,0,xy };
			newBoard[shark.xy.first][shark.xy.second] = 0; // 기존 상어 위치 비우기
			newBoard[xy.first][xy.second] = -1; // 이동 위치에 상어 올리기

			dfs(newShark, newFish, newBoard, newShark.point);
		}
	}
	else { // 먹방 못하면 point 갱신
		maxPoint = max(maxPoint, point);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<int>> board(4, vector<int>(4, -1)); // 현재 보드의 정보
	Fish fish[17]; // 각 좌표의 1~16번 물고기 정보
	Shark shark; // 상어의 방향, 현재 위치, 먹은 물고기 합

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			board[i][j] = num;
			fish[num] = { num, dir, {i,j} };
		}
	}

	// 1. 상어 (0,0) 이동
	shark = { fish[board[0][0]].dir, fish[board[0][0]].xy, fish[board[0][0]].num };
	fish[board[0][0]] = { 0,0,{0,0} };
	board[0][0] = -1; // 상어가 있으면 -1, 빈칸이면 0

	// 2. 물고기 이동 -> 물고기 방향으로 상어 이동 -> 물고기 이동
	// 물고기 이동: 1번부터 16번 순차 진행
	// 상어 이동: 먹은 물고기 방향에 있는 물고기들을 먹는 경우의 수를 큐로 담고 각 큐에 대해서 다음 분기 진행
	// 상어가 이동할 수 있을 때 까지 반복

	// dfs로 탐색
	dfs(shark, fish, board, shark.point);

	cout << maxPoint;

	return 0;
}