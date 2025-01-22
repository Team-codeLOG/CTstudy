n = int(input())
body = []
body_size = []

for i in range(n):
    body.append(list(input()))

for i in range(len(body)):
    cnt = body[i].count("*")
    if cnt == 1: 
        heart_x = i+1
        heart_y = body[i].index("*")
        break

left_arm = body[heart_x][:heart_y].count("*")
right_arm = body[heart_x][heart_y+1:].count("*")


body = body[heart_x+1:]
cnt_w = 0

for i in range(len(body)):
    cnt = body[i].count("*")
    if cnt == 1: 
        cnt_w += 1
    else:
        waist_x = i
        waist_y = heart_y
        break

body = body[waist_x:]

left_leg = 0
right_leg = 0

for i in range(len(body)):
    if body[i][waist_y -1] == "*":
        left_leg += 1
    if body[i][waist_y +1] == "*":
        right_leg +=1 

print(heart_x+1, heart_y+1)
print(left_arm, right_arm, cnt_w, left_leg, right_leg)