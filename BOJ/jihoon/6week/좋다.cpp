#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, goodCnt = 0;
ll arr[2001];

// i��° �ε���
bool binarySearch(int i) {
    // i��° �ε��� = j��° �ε��� + mid�ε���(�̺�Ž�� �ε���)
    for (int j = 0; j < N; j++) {
        if (j == i) continue; // �ڱ� �ڽ��̶�� �н�

        int s = 0, e = N - 1;

        while (s <= e) {
            int mid = (s + e) / 2;
            ll sum = arr[j] + arr[mid];
            if (mid == i || mid == j) {
                if (mid < i) s = mid + 1;
                else e = mid - 1;
                continue;
            }

            if (sum == arr[i]) return true;
            else if (sum > arr[i]) e = mid - 1;
            else s = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    // �̺�Ž������ i��° �ε����� �ٸ� �� �� ���� ������ ��Ÿ�� �� �ִ��� Ȯ��
    for (int i = 0; i < N; i++) {
        if (binarySearch(i)) goodCnt++;
    }

    cout << goodCnt;

    return 0;
}