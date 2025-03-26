#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N;
unordered_map<char, int> um;

// 단축키 지정 및 출력 함수 -> 전부 소문자로 판단
void shortKey(string str) {
	// 방법 1 - 각 단어의 첫번째 알파벳
	for (int i = 0; i < str.length(); i++) {
		if (i == 0 || str[i - 1] == ' ') {
			// 없다면 해당 단어 출력 및 단축키 등록
			if (um.find(tolower(str[i])) == um.end()) {
				cout << str.substr(0, i) << "[" << str[i] << "]";
				if (i < str.size() - 1) {
					cout << str.substr(i + 1);
				}
				cout << "\n";
				um.insert({ tolower(str[i]), 1 });
				return;
			}
		}
	}

	// 방법 2 - 모든 단어를 조회하며 단축키 아닌 알파벳
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			if (um.find(tolower(str[i])) == um.end()) {
				cout << str.substr(0, i) << "[" << str[i] << "]";
				if (i < str.size() - 1) {
					cout << str.substr(i + 1);
				}
				cout << "\n";
				um.insert({ tolower(str[i]), 1 });
				return;
			}
		}
	}

	// 방법 3 - 그냥 출력
	cout << str << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		shortKey(str);
	}

	return 0;
}