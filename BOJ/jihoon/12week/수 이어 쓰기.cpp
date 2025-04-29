#include <bits/stdc++.h>

using namespace std;

int idx = 0; // 입력 문자열에서 비교할 인덱스
int num = 0; // 1부터 시작해서 하나씩 늘려가며 확인할 숫자
// 1부터 누적된 자릿수의 누적합이 최소 3000
// 그러면 9 + 90 * 2 + 900 * 3 = 9 + 180 + 2700 > 3000
// 1889 번째 자리에 올 수 있는 최소 숫자는 999 => int로 충분

string str;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> str;

	// 입력받은 문자열 모두 탐색할 때까지
	while (idx < str.length()) {
		num++;
		string n = to_string(num); // 현재 숫자 문자열로

		// 현재 판단하고 있는 숫자의 왼쪽부터 체크
		for (char c : n) {
			// 같지 않은 숫자는 지워진 숫자라고 판단
			if (c == str[idx]) {
				idx++; // 같다면 str의 다음 숫자 판단
				if (idx == str.length()) break; // 모든 숫자를 다 찾았으면 종료
			}
		}
	}

	cout << num;

	return 0;
}