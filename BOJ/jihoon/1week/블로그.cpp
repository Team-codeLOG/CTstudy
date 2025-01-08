#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector<int> visitNum;

// �湮�� �� �Է�
void input() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		visitNum.push_back(n);
	}
}

// �����̵� ������ -> X�ϵ����� �ִ� ���ϱ�
void slidingWindow() {
	long long sum = 0;
	long long maxSum = 0;
	int count = 1;

	// 1~X�ϱ��� �湮�� ���� ��
	for (int i = 0; i < X; i++) {
		sum += visitNum[i];
	}
	maxSum = sum;

	// �����̵� ������� �����ڸ��� ���� ���ϸ� �̵�
	for (int i = X; i < N; i++) {
		sum = sum - visitNum[i - X] + visitNum[i];  // ���ο� �� ���

		// �ִ� ����
		if (sum > maxSum) {
			maxSum = sum;
			count = 1;
		}
		// ���� �ִ� ����� count ����
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