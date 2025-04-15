# 사무실 크기 입력 받는다
n, m = map(int, input().split())

# 사무실을 입력 받는다
arr = []
dict = {}
answer = 0
for i in range(n):
    line = list(map(int, input().split()))
    for j in range(m):
        if (line[j]>0):
            if (line[j] in dict):
                dict[line[j]].append([i,j])
            else:
                dict[line[j]] = [[i,j]]
            answer += 1
    arr.append(line)
    
# print(arr)
# print(dict)

for num in range(5, 0, -1):
    if (num in dict):
        for k in dict[num]:
            cnt = {'left_cnt': 0, 'right_cnt': 0, 'top_cnt': 0, 'bottom_cnt': 0}
            for kk in range(k[0]-1, -1, -1):
                if(arr[kk][k[1]] == 6): break
                if(arr[kk][k[1]]=="#" or arr[kk][k[1]]>0): continue
                cnt['left_cnt'] += 1
            # 우
            for kk in range(k[0]+1, n, 1):
                if(arr[kk][k[1]] == 6): break
                if(arr[kk][k[1]]=="#" or arr[kk][k[1]]>0): continue
                cnt['right_cnt'] += 1
            # 상
            for kk in range(k[1]-1, -1, -1):
                if(arr[k[0]][kk] == 6): break
                if(arr[k[0]][kk]=="#" or arr[k[0]][kk]>0): continue
                cnt['top_cnt'] += 1
            # 하
            for kk in range(k[1]+1, m, 1):
                if(arr[k[0]][kk] == 6): break
                if(arr[k[0]][kk]=="#" or arr[k[0]][kk]>0): continue
                cnt['bottom_cnt'] += 1

            if (num in [4,5]):
                selected = sorted(cnt.items(), key=lambda x:-x[1])[:num-1]
            elif (num==1):
                selected = sorted(cnt.items(), key=lambda x:-x[1])[:num]
            elif(num == 2):
                dir1 = cnt['top_cnt'] + cnt['bottom_cnt']
                dir2 = cnt['left_cnt'] + cnt['right_cnt']
                if (dir1>=dir2): selected = [('top_cnt', cnt['top_cnt']), ('bottom_cnt', cnt['bottom_cnt'])]
                else: selected = [('right_cnt', cnt['right_cnt']), ('left_cnt', cnt['right_cnt'])]
            elif(num == 3):
                dir1 = cnt['top_cnt'] + cnt['left_cnt']
                dir2 = cnt['top_cnt'] + cnt['right_cnt']
                dir3 = cnt['bottom_cnt'] + cnt['left_cnt']
                dir4 = cnt['bottom_cnt'] + cnt['right_cnt']
                max_dir = max(dir1, dir2, dir3, dir4)
                if(max_dir==dir1): selected = [('top_cnt', cnt['top_cnt']), ('left_cnt', cnt['left_cnt'])]
                elif(max_dir==dir2): selected = [('top_cnt', cnt['top_cnt']), ('right_cnt', cnt['right_cnt'])]
                elif(max_dir==dir3): selected = [('bottom_cnt', cnt['bottom_cnt']), ('left_cnt', cnt['left_cnt'])]
                elif(max_dir==dir4): selected = [('bottom_cnt', cnt['bottom_cnt']), ('right_cnt', cnt['right_cnt'])]

            # print(selected)

            for r in selected:
                if(r[0]=="left_cnt"):
                    for kk in range(k[0]-1, -1, -1):
                        if(arr[kk][k[1]] == 6): break
                        if(arr[kk][k[1]]=="#" or arr[kk][k[1]]>0): continue
                        arr[kk][k[1]] = "#"
                        answer += 1
                elif(r[0]=="right_cnt"):
                    for kk in range(k[0]+1, n, 1):
                        if(arr[kk][k[1]] == 6): break
                        if(arr[kk][k[1]]=="#" or arr[kk][k[1]]>0): continue
                        arr[kk][k[1]]="#"
                        answer += 1
                elif(r[0]=="top_cnt"):
                    for kk in range(k[1]-1, -1, -1):
                        if(arr[k[0]][kk] == 6): break
                        if(arr[k[0]][kk]=="#" or arr[k[0]][kk]>0): continue
                        arr[k[0]][kk]="#"
                        answer += 1
                elif(r[0]=="bottom_cnt"):
                    for kk in range(k[1]+1, m, 1):
                        if(arr[k[0]][kk] == 6): break
                        if(arr[k[0]][kk]=="#" or arr[k[0]][kk]>0): continue
                        arr[k[0]][kk]="#"
                        answer += 1
                print("----")
                for a in arr:
                    print(*a)
    

print(max(0, n*m - answer))


