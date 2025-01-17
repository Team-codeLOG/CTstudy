
test_n = int(input())
for _ in range(test_n):
    days_n = int(input())
    arr = list(map(int, input().split()))
    profit = 0
    max_price = 0 
    for price in reversed(arr):
        if price > max_price:
            max_price = price
        else:
            profit += (max_price - price)
    print(profit)
