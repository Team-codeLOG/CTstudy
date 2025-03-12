#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[1000001];

long long sw() {
	long long iceMax = 0;
	int s = 0, e = 2 * K;

	// 얼음 초기값
	for (int i = s; i <= e; i++) {
		if (i > 1000000) break; // 인덱스 초과하면 종료
		iceMax += arr[i];
	}

	long long ice = iceMax;

	while (e <= 1000000) {
		ice -= arr[s]; // 기존 첫 값 삭제
		s++, e++;
		ice += arr[e]; // 새로운 끝 값 추가
		iceMax = max(iceMax, ice);
	}
	return iceMax;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	int g, x;
	for (int i = 0; i < N; i++) {
		cin >> g >> x;
		arr[x] = g;
	}

	cout << sw();

	return 0;
}