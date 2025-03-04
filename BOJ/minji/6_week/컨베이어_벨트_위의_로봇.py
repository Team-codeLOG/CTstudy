from collections import deque

n, k = map(int, input().split())
durability = deque(map(int, input().split()))
robots = deque([0] * n)
turn_count = 0

while True:
    turn_count += 1
    durability.rotate(1)
    robots.rotate(1)
    robots[-1] = 0

    for i in range(n - 2, -1, -1):
        if durability[i + 1] > 0 and robots[i + 1] == 0 and robots[i] == 1:
            robots[i + 1] = 1
            robots[i] = 0
            durability[i + 1] -= 1

    robots[-1] = 0

    if durability[0] > 0 and robots[0] == 0:
        robots[0] = 1
        durability[0] -= 1
    if durability.count(0) >= k:
        break

print(turn_count)
