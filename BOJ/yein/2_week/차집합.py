na, nb = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# 시간초과
# arr = []
# for aa in a:
#     if (aa not in b):
#         arr.append(aa)

# 시간초과 22
# arr = [x for x in a if x not in b]

arr = set(a)-set(b)

print(len(arr))
if (len(arr)!=0):
    for i in sorted(arr):
        print(i, end=" ")
