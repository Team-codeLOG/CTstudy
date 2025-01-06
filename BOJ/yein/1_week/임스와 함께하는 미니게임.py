n, game = input().split(" ")
arr = []
for _ in range(int(n)):
  arr.append(input())
arr = set(arr)
if (game == "Y"):
  need = 1
elif (game == "F"):
  need = 2
elif (game == "O"):
  need = 3
print(len(arr)//need)
