#include <iostream>

using namespace std;

int X;

void input() {
	cin >> X;
}

void caculate() {
	// 1  3  6  10  15
	//  +2 +3 +4 +5
	int count = 1; // 1부터 시작
	while (1) {
		X -= count;
		if (X <= 0) break;
		count++; // 빼는 숫자 증가
	}

	// 빼는 숫자가 짝수인 경우 - 1 / count 스타트
	if (count % 2 == 0) {
		cout << count + X << "/" << 1 - X << "\n";
	}
	// 빼는 숫자가 홀수인 경우 - count / 1 스타트
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