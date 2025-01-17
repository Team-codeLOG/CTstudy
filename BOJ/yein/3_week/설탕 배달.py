n = int(input())
answer = -1
max5 = n//5
for i in range(max5, -1, -1): #5키로 최대개수부터 0개까지
    curr = n - 5*i
    if (curr % 3) == 0 : # 나눠떨어짐
        answer = i + (curr/3)
        break

print(int(answer))
