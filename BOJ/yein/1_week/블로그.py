# 블로그
days, x = map(int, input().split(" "))
arr = list(map(int, input().split(" ")))

curr_sum = sum(arr[:x]) # 현재 값
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


'''
시간이 초과된 초기 코드에서, 문제가 되는 부분은 이중 반복문이었습니다.
블로그 운영 기간(days)를 N, 계산 기간(x)를 M이라 했을 때,
시간 복잡도는 O(N*M)이 되고, 요구조건을 만족시키지 못하였습니다.

따라서, 연속된 x일간의 방문자 수를 계산하는 부분을 개선하였습니다.
사용된 개념은 #슬라이딩 윈도우 알고리즘
새로운 코드에서, x일간의 방문자 수는 x번 반복이 아닌,
지나간 1일(prev_element)은 버리고 새로운 날짜(new_element, i번째 현재 날짜)는 더하는 방식이 되어
시간 복잡도는 O(N)으로 줄어들게 됩니다. 통과!
'''

# 블로그 - 실패 (시간초과)
# days, x = map(int, input().split(" "))
# arr = list(map(int, input().split(" ")))

# visitor = [0 for _ in range(days-x+1)]
# for i in range(0, days-x+1):
#   for j in range(x):
#     visitor[i] += arr[i+j]
    
# maxVisitor = max(visitor)

# if (maxVisitor == 0):
#   print("SAD")
# else:
#   print(maxVisitor)
#   count = 0
#   for i in range(len(visitor)):
#     if(visitor[i] == maxVisitor): count += 1
#   print(count)
