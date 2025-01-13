#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector<int> visitNum;

// 방문자 수 입력
void input() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		visitNum.push_back(n);
	}
}

// 슬라이딩 윈도우 -> X일동안의 최댓값 구하기
void slidingWindow() {
	long long sum = 0;
	long long maxSum = 0;
	int count = 1;

	// 1~X일까지 방문자 수의 합
	for (int i = 0; i < X; i++) {
		sum += visitNum[i];
	}
	maxSum = sum;

	// 슬라이딩 윈도우로 가장자리를 빼고 더하며 이동
	for (int i = X; i < N; i++) {
		sum = sum - visitNum[i - X] + visitNum[i];  // 새로운 합 계산

		// 최댓값 갱신
		if (sum > maxSum) {
			maxSum = sum;
			count = 1;
		}
		// 동일 최댓값 존재시 count 증가
		else if (sum == maxSum) count++;
	}

	if (maxSum == 0) cout << "SAD";
	else {
		cout << maxSum << "\n" << count;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	input();
	slidingWindow();

	return 0;
}