n, k = map(int, input().split())
table = list(input())
count = 0

for i in range(n):
    if table[i] == "P":
        start = max(0, i - k)
        end = min(n, i + k+1)
        
        for j in range(start, end):
            if table[j] == "H":
                count += 1
                table[j] = None
                break 

print(count)