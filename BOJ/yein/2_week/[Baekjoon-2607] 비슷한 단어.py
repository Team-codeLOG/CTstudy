n = int(input())
first= sorted(input())
cnt = 0
    
for _ in range(n-1):
    first_copy = first.copy()
    word = input()
    err_cnt = 0

    for w in word:
        if (w in first_copy): first_copy.remove(w)
        else: err_cnt += 1

    if (err_cnt < 2 and len(first_copy)<2): cnt+=1
    # else: print(f"{word}에서 오류 발생, {err_cnt}개의 다른 원소, {first_copy} 남음")

print(cnt)
