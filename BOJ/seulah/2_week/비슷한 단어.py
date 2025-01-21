from collections import Counter

# 입력 받기
n = int(input())
target = input()
words = [input() for _ in range(n - 1)]

# 기준 단어의 문자 빈도 계산
target_cnt = Counter(target)
cnt = 0

# 각 단어와 비교
for word in words:
    word_cnt = Counter(word)

    # 모든 문자의 차이를 계산
    all_chars = set(target_cnt) | set(word_cnt)
    diff = 0
    for char in all_chars:
        diff += abs(target_cnt[char] - word_cnt[char])

    # 비슷한 단어 조건 판단
    if (len(target) == len(word) and diff <= 2) or (abs(len(target) - len(word)) == 1 and diff == 1):
        cnt += 1

# 결과 출력
print(cnt)
