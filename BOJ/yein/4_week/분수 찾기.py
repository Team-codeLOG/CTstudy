N = int(input())

line = 0
while(N > 0):
    line += 1
    N -= line
N += line

if(line%2==1):
    left = line
    right = 1
    for _ in range(N-1):
        left -= 1
        right += 1
else:
    left = 1
    right = line
    for _ in range(N-1):
        left += 1
        right -= 1

print(f"{left}/{right}")
