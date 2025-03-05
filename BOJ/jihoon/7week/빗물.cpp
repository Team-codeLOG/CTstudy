#include <bits/stdc++.h>

using namespace std;

int world[501][501];
int H, W;

int waterCal() {
    int water = 0;
    // 바닥 행부터 탐색
    // 블록 - 블록 사이의 칸을 계산하고 닫힌다면 더하기
    for (int h = H - 1; h >= 0; h--) {
        int startblock = -1;
        int endblock = -1;
        for (int w = 0; w < W; w++) {
            // 블록이라면
            if (world[w][h] == 1) {
                // 시작블록이 추가되지 않은 상태라면
                if (startblock == -1) {
                    startblock = w;
                }
                else {
                    endblock = w;

                    // 빗물 추가
                    water += endblock - startblock - 1;

                    // 시작 블록 초기화
                    startblock = w;
                }
            }
        }
    }
    return water;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        int depth;
        cin >> depth;
        for (int j = H - 1; j > H - 1 - depth; j--) {
            world[i][j] = 1; // 1이면 블록 존재
        }
    }

    int result = waterCal();

    return 0;
}