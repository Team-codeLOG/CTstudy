import sys
input = sys.stdin.readline

n = int(input())
arr = sorted(list(map(int, input().split())))
good = 0

for i in range(n):
    left , right = 0, n-1
    target = arr[i]

    while left < right:
        if i == left:
            left+=1
            continue
        if i == right:
            right-=1
            continue

        total = arr[left]+arr[right]
        if target < total:
            right -=1
        elif target > total:
            left +=1
        else:
            good+=1
            break
print(good)







