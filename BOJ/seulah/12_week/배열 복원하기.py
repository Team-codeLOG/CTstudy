H,W,X,Y = map(int,input().split())
B = [list(map(int,input().split())) for _ in range(H+X)]
A = [[0]*W for _ in range(H)]
for i in range(X,H+X):
    for j in range(Y,W+Y):
        B[i][j] = B[i][j]-B[i-X][j-Y]

for i in range(H):
    for j in range(W):
        A[i][j] = B[i][j]

for row in A:
    print(" ".join(map(str,row)))

