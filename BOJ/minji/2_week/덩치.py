n = int(input())
hwList = []
countList = []
for i in range(n):
    hw = list(map(int, input().split()))
    hwList.append(hw)

for i in range(n):
    tmpCount = 1
    for j in range(n):
        if (hwList[i][0] < hwList[j][0]) and (hwList[i][1] < hwList[j][1]):
            tmpCount += 1
    countList.append(tmpCount)
print(*countList)


