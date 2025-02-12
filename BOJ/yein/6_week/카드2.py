from collections import deque

N = int(input())
arr = [i for i in range(N, 0, -1)]
arr = deque(arr)

stage = 0

while(len(arr)!=1):
    if (stage%2==0):
        arr.pop()
    if (stage%2==1):
        temp = arr.pop()
        arr.appendleft(temp)
    stage += 1
    
print(*arr)

