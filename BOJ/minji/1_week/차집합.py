a, b = map(int, input().split())
a_set = set(map(int, input().split()))
b_set = set(map(int, input().split()))

difference_set = a_set - b_set

if len(difference_set) > 0:
   print(len(difference_set))
   print(*sorted(difference_set))
else:
    print(0)
