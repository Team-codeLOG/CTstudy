days, x = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

curr_sum = sum(arr[:x])
visitors = [curr_sum]

for i in range(x, days):
  prev_element = arr[i-x]
  new_element = arr[i]
  curr_sum = curr_sum - prev_element + new_element
  visitors.append(curr_sum)

max_sum = max(visitors)
count = 0
if (max_sum == 0):
  print("SAD")
else:
  print(max_sum)
  for j in range(0, len(visitors)):
       if (visitors[j] == max_sum): count+=1
  print(count)
