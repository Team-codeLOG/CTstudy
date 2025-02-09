import sys

N = int(sys.stdin.readline())
arr = []

def heapify(arr):
    curr_idx = len(arr)-1
    while (1):
        if (curr_idx <= 0): break
        parent_idx = (curr_idx - 1)//2
        if (arr[curr_idx] < arr[parent_idx]):
            (arr[curr_idx], arr[parent_idx]) = (arr[parent_idx], arr[curr_idx])
            curr_idx = parent_idx
            continue
        break

def downHeap(arr):
    curr_idx = 0
    last_idx = len(arr)-1
    while(1):
        if(curr_idx >= last_idx): break
        left_child_idx = (curr_idx+1)*2-1
        right_child_idx = (curr_idx+1)*2
        if(left_child_idx <= last_idx and right_child_idx <= last_idx):
            left_child = arr[left_child_idx]
            right_child = arr[right_child_idx]
            min_idx = left_child_idx if(left_child <= right_child) else right_child_idx
        elif(left_child_idx <= last_idx): min_idx = left_child_idx
        elif(right_child_idx <= last_idx): min_idx = right_child_idx
        if(arr[min_idx] < arr[curr_idx]):
                (arr[curr_idx], arr[min_idx]) = (arr[min_idx], arr[curr_idx])
                curr_idx = min_idx
                continue
        else: break

for _ in range(N):
    num = int(sys.stdin.readline())
    if (num==0):
        if (len(arr)!=0):
            print(arr[0])
            arr[0] = arr[-1]
            arr.pop()
            if (len(arr)!=0):downHeap(arr)
        else :
            print("0")
    else:
        arr.append(num)
        heapify(arr)
        
