T = int(input())
for _ in range(T):
    n = int(input())
    prices = list(map(int, input().split()))

    # 최대 가격을 기준으로 탐색
    max_price = 0
    max_profit = 0

    # 뒤에서부터 주식 가격 확인
    for price in reversed(prices):
        if price > max_price:
            max_price = price  # 새로운 최대 판매 가격 갱신
        else:
            max_profit += max_price - price  # 최대 판매 가격으로 이익 계산

    print(max_profit)
