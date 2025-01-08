#include <iostream>
#include <set>

using namespace std;

int N; // 게임 신청 횟수
char gType; // 게임 타입
set<string> people; // 플레이 인원

void inputPeople() {
	cin >> N >> gType;
	for (int i = 0; i < N; i++) {
		string person;
		cin >> person;
		people.insert(person);
	}
}

void solve() {
	if (gType == 'Y') cout << people.size();
	else if (gType == 'F') cout << people.size() / 2;
	else if (gType == 'O') cout << people.size() / 3;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	inputPeople(); // 플레이 인원 입력
	solve();

	return 0;
}