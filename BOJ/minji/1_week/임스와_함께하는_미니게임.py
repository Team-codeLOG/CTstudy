n, game = input().split()

if (game == "Y"):
    player_num = 2
elif (game == "F"):
    player_num = 3
else:
    player_num = 4

player_list = []

for i in range(int(n)):
    player_list.append(input())

player_list = list(set(player_list))

print(len(player_list)//(player_num-1))