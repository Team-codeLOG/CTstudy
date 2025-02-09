x = int(input())


def find_largest_number(x):
    num = 1
    i = 1

    while num + i <= x:
        num += i
        i += 1

    return num, i


largest_num, idx = find_largest_number(x)
position = x - largest_num + 1

if idx % 2 == 1:
    print(f"{idx - (position - 1)}/{position}")
else:
    print(f"{position}/{idx - (position - 1)}")
