# 1253 좋다

N = int(input())
arr = sorted(list(map(int, input().split())))
ans = 0

for i in range(N):
    target = arr[i]
    left_idx = 0
    # right_idx = i-1 # 음수 있을 때 망함!!!
    right_idx = N-1

    while(left_idx < right_idx):
        if(left_idx == i):
            left_idx += 1
            continue
        if(right_idx == i):
            right_idx -= 1
            continue
        
        curr_sum = arr[left_idx] + arr[right_idx]

        if (curr_sum == target):
            ans += 1
            break
        else:
            # 포인터 이동하기
            if (curr_sum > target): right_idx -= 1
            elif (curr_sum < target): left_idx += 1

print(ans)

    
    
