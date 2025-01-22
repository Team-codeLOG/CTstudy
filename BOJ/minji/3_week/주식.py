def solution(x):
    max_price = 0
    profit = 0

    for i in range(len(x)-1,-1,-1):
        if x[i]>max_price:
            max_price = x[i]
        else:
            profit += max_price - x[i]
    return profit

n = int(input())
for i in range(n):
    n = int(input())
    x = list(map(int, input().split()))
    print(solution(x))