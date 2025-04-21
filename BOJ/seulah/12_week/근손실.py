from itertools import permutations

N,K = map(int,input().split())
kits = list(map(int,input().split()))
cnt = 0

for kit in permutations(kits):
    weight = 500
    for i in kit:
        weight += i-K
        if weight<500:
            break
    else:
        cnt+=1
print(cnt)
