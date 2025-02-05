head = False
arm = False
waist = False
waist_len = 0
left_leg_idx = 0
right_leg_idx = 0
left_leg = 1
right_leg = 1

n = int(input())

for i in range(n):
    line = input()
    if (("*" in line) & (not head)):
        head = True
        heart_r = 2+i
        heart_c = line.index("*") + 1
        arm = True
    elif (arm):
        arm = False
        total_arm = line.count("*")
        start_arm = line.index("*") + 1
        left_arm = heart_c - start_arm
        right_arm = total_arm - 1 - left_arm
        waist = True
    elif (waist):
        waist_len += 1
        if (line.count("*")==2):
            waist_len -= 1
            waist = False
            left_leg_idx = line.index("*")
            right_leg_idx = line[left_leg_idx+1:].index("*") + left_leg_idx + 1
    else:
        if(line[left_leg_idx] == "*"): left_leg += 1
        if(line[right_leg_idx] == "*"): right_leg += 1
        
   
print(heart_r, heart_c)
print(left_arm, right_arm, waist_len, left_leg, right_leg)
