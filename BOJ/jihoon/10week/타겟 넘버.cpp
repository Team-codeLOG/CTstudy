/*** DFS 풀이 ***/

#include <bits/stdc++.h>

using namespace std;

int answer = 0;
void dfs(vector<int> numbers, int target, int idx, int sum) {
    if (idx == numbers.size()) { // 끝에 도달
        if (sum == target) { // target 완성
            answer++;
        }
        return;
    }

    dfs(numbers, target, idx + 1, sum + numbers[idx]); // +1
    dfs(numbers, target, idx + 1, sum - numbers[idx]); // -1
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, target, 0, 0);

    return answer;
}


/*** BFS 풀이 ***/

/*
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target){
    int answer = 0;
    queue<int> Q;
    Q.push(numbers[0]);
    Q.push(-1 * numbers[0]);

    for(int i=1; i<numbers.size(); i++){
        int len = Q.size();
        for(int j=0; j<len; j++){
            int sum = Q.front();
            Q.pop();
            Q.push(sum + numbers[i]);
            Q.push(sum - numbers[i]);
        }
    }
    int len = Q.size();
    for(int i=0; i<len; i++){
        if(Q.front() == target)
            answer++;
        Q.pop();
    }

    return answer;
}
*/