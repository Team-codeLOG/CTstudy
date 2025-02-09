import sys
input = sys.stdin.readline

X = int(input())
line = 1

while X > line:
    X -= line
    line += 1

# 짝수일경우
if line % 2 == 0:
    a = X
    b = line - X + 1
# 홀수일경우
elif line % 2 == 1:
    a = line - X + 1
    b =  X

print(f'{a}/{b}')