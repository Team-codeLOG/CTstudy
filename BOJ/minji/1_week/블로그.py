n, x = map(int, input().split())
visit_num = list(map(int, input().split()))

max_value = sum(visit_num[:x]) 
current_sum = max_value
count = 1

for i in range(n-x):
    current_sum = current_sum - visit_num[i] + visit_num[i+x]
    if current_sum > max_value:
        max_value = current_sum
        count = 1
    elif current_sum == max_value:
        count += 1

if max_value == 0:
    print("SAD")
else:
    print(max_value)
    print(count)