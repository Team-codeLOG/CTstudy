import sys
input = sys.stdin.readline

N,K = map(int,input().split())
ham = list(input().strip())
cnt =0

for i in range(N):
    if ham[i] =="P":
        left = i-K
        right = i+K+1

        if left < 0:  # 왼쪽 범위가 0보다 작으면 0
            left = 0
        if right > N:  # 오른쪽 범위가 N을 초과하면 N으로 설정
            right = N

        for j in range(left,right):
            if ham[j] == "H":
                ham[j] = "1"
                break

print(ham.count("1"))