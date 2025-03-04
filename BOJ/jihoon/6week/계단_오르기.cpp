#include <bits/stdc++.h>

using namespace std;

int N; // 계단의 개수
int score[301];
int dp[301];

// dp 초기화
void dpInit() {
    dp[0] = 0;
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1], score[2]) + score[3];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    score[0] = 0;
    for(int i=1; i<=N; i++) cin >> score[i];
    
    dpInit();
    for(int i=4; i<=N; i++) {
        dp[i] = max(dp[i-2], dp[i-3] + score[i-1]) + score[i];
    }
    
    cout << dp[N];
    
    return 0;
}
