#include <bits/stdc++.h>

using namespace std;

int N, K; // 컨베이어 벨트 길이(N), 내구도 0개수 최대값(K)
int A[201]; // 각 위치의 내구도
int robot[201]; // 로봇 위치
int level = 0; // 수행 단계
int s, e; // 시작점 - 올리는 위치, 내리는 위치
int zeroCnt = 0; // 내구도가 0인 칸의 개수

// 조건1: 벨트와 로봇 회전
// 조건2: 로봇 한칸 이동 or 정지 => 이동하려는 칸에 로봇 x & 이동 칸의 내구도 > 0
// 조건3: 올리는 위치 칸 내구도 > 0 이면 로봇 올리기
// 조건4: 내구도 0인 칸 개수 >= K 면 종료
// => 종료되었을 때, level 출력

// 로봇 내리기
void removerobot() {
    robot[e] = 0;
}

// 로봇 올리기
void addrobot() {
    if(A[s] > 0 && robot[s] == 0){
        robot[s] = 1;
        A[s]--;
        if(A[s] == 0) zeroCnt++;
    }
}

void move() {
    int idx = e;
    for(int i=1; i<N; i++){
        int next = idx;
        idx--;
        if(idx == 0) idx = 2 * N;
        // 로봇이 올라가있다면
        if(robot[idx] == 1) {
            // 다음칸 이동
            if(robot[next] == 0 && A[next] > 0){
                // 이동 및 내구도 감소
                robot[idx] = 0;
                robot[next] = 1;
                A[next]--;
                
                // 내구도 0이 되면 zeroCnt 증가
                if(A[next] == 0) zeroCnt++;
            }
        }
    }
    // 내리는 위치는 항상 비우기
    removerobot();
}

void rotation() {
    s--;
    e--;
    if(e == 0) e = 2 * N;
    if(s == 0) s = 2 * N;
    
    // 로봇이 내리는 위치에 도달하면 내림
    if(robot[e] == 1)
        removerobot();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=1; i<=2*N; i++) cin >> A[i];
    
    s = 1, e = N; // 시작점 - 올리는 위치, 내리는 위치
    
    // 조건4를 만족할 때까지 반복
    while(zeroCnt < K) {
        // 조건1 - 회전
        rotation();
        // 조건2 - 로봇 이동
        move();
        // 조건3 - 로봇 올리기
        addrobot();
        level++;
    }
    
    cout << level;
    
    return 0;
}
