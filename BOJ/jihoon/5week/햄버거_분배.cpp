#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[20000];
vector<int> ppos;

int findBurger() {
	int resultCnt = 0;

	for (int i = 0; i < ppos.size(); i++) {
		// 왼쪽 최대 거리부터 오른쪽 최대 거리까지 햄버거 찾기
		for (int s = max(ppos[i] - K, 0); s <= min(ppos[i] + K, N - 1); s++) {
			// 햄버거를 찾았다면 먹고 break
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
		// 사람인 경우 1, 햄버거인 경우 2 저장
		if (str[i] == 'P') {
			arr[i] = 1;
			ppos.push_back(i);
		}
		else arr[i] = 2;
	}

	cout << findBurger();

	return 0;
}