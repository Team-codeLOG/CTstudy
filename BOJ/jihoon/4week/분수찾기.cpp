#include <iostream>

using namespace std;

int X;

void input() {
	cin >> X;
}

void caculate() {
	// 1  3  6  10  15
	//  +2 +3 +4 +5
	int count = 1; // 1���� ����
	while (1) {
		X -= count;
		if (X <= 0) break;
		count++; // ���� ���� ����
	}

	// ���� ���ڰ� ¦���� ��� - 1 / count ��ŸƮ
	if (count % 2 == 0) {
		cout << count + X << "/" << 1 - X << "\n";
	}
	// ���� ���ڰ� Ȧ���� ��� - count / 1 ��ŸƮ
	else if (count % 2 != 0) {
		cout << 1 - X << "/" << count + X << "\n";
	}
}

void solve() {
	input();
	caculate();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();

	return 0;
}