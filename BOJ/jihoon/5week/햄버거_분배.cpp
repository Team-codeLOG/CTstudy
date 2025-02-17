#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[20000];
vector<int> ppos;

int findBurger() {
	int resultCnt = 0;

	for (int i = 0; i < ppos.size(); i++) {
		// ���� �ִ� �Ÿ����� ������ �ִ� �Ÿ����� �ܹ��� ã��
		for (int s = max(ppos[i] - K, 0); s <= min(ppos[i] + K, N - 1); s++) {
			// �ܹ��Ÿ� ã�Ҵٸ� �԰� break
			if (arr[s] == 2) {
				resultCnt++;
				arr[s] = 0;
				break;
			}
		}
	}

	return resultCnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		// ����� ��� 1, �ܹ����� ��� 2 ����
		if (str[i] == 'P') {
			arr[i] = 1;
			ppos.push_back(i);
		}
		else arr[i] = 2;
	}

	cout << findBurger();

	return 0;
}