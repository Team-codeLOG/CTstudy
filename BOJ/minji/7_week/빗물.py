h, w = map(int, input().split())

block = list(map(int, input().split()))


sum = 0
start = -1
end = -1

for i in range(1, w-1):
    start = max(block[:i])
    end = max(block[i+1:])

    h = min(start, end)

    if block[i] < h:
        sum += h - block[i]

print(sum)