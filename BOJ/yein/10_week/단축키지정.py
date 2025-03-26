import sys
# 단어 개수
N = int(sys.stdin.readline())
shortcut = []

# 출력할 배열
arr = []

for _ in range(N):
    registered = False
    line = sys.stdin.readline().replace("\n", "")
    if(line[0] not in shortcut and line[0]!=" "):
        shortcut.append(line[0].upper())
        shortcut.append(line[0].lower())
        arr.append("["+line[0]+"]"+line[1:])
        registered = True
    elif(not registered):
        i = 0
        flag = False
        max_length = len(line)
        while(1):
            if(i>=max_length): break
            else:
                if(flag):
                    if(line[i] not in shortcut and line[i]!=" "):
                        shortcut.append(line[i].upper())
                        shortcut.append(line[i].lower())
                        arr.append(line[:i]+"["+line[i]+"]"+line[min(max_length,i+1):])
                        registered = True
                        break
                    flag = False
                if(line[i]==" "):
                    flag = True
                else:
                    flag = False
                i+=1
    if(not registered):
        for ii in range(len(line)):
            l = line[ii]
            if(l not in shortcut and l != " "):
                shortcut.append(l.upper())
                shortcut.append(l.lower())
                arr.append(line[:ii]+"["+line[ii]+"]"+line[min(max_length,ii+1):])
                registered = True
                break
    if(not registered):
        arr.append(line)


for iii in range(N):
    print(arr[iii])
