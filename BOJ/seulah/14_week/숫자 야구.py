# 영수가 생각하는 정답의 모든 수 넣어보기
# 민혁이가 도전한 내용에 맞는지 확인하기

N = int(input())
hint = [list(map(int,input().split())) for _ in range(N)]
answer = 0


for a in range(1,10): # 백의 자리수
    for b in range(1,10): # 십의 자리수
        for c in range(1,10): # 일의 자리수

            if (a==b or b==c or c==a):
                continue

            cnt = 0
            # 숫자가 정해졌다면
            for number, strike, ball in hint:
                ball_cnt , strike_cnt = 0,0
                num = str(number)
                x,y,z = int(num[0]), int(num[1]), int(num[2])

                if a == x : strike_cnt+=1
                if b == y : strike_cnt+=1
                if c == z : strike_cnt+=1

                if a==y or a==z : ball_cnt+=1
                if b==x or b==z : ball_cnt+=1
                if c==x or c==y : ball_cnt+=1

                #abc를 number과 비교
                if ball == ball_cnt and strike == strike_cnt:
                    cnt+=1
            if cnt==N:
                answer+=1

print(answer)