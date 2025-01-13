#include <iostream>
#include <set>

using namespace std;

int N; // ���� ��û Ƚ��
char gType; // ���� Ÿ��
set<string> people; // �÷��� �ο�

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

	inputPeople(); // �÷��� �ο� �Է�
	solve();

	return 0;
}