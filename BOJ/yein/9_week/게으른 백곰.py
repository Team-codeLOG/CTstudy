N, K = map(int, input().split())

ice = {}
max_dist = 0
for _ in range(N):
    g, x = map(int, input().split())
    ice[x] = g
    max_dist = max(max_dist, x)

arr = []
for j in range(max_dist+1):
    if(j in ice): arr.append(ice[j])
    else: arr.append(0)

curr_sum = sum(arr[:min(2 * K + 1, max_dist + 1)])
curr_max = curr_sum

for k in range(1, max_dist + 1 - K):
    left = arr[k - 1] if k - 1 >= 0 else 0
    right = arr[k + 2 * K] if k + 2 * K <= max_dist else 0
    curr_sum = curr_sum - left + right
    curr_max = max(curr_max, curr_sum)

print(curr_max)