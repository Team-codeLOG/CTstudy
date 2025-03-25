from collections import deque

def solution(numbers, target):
    n = len(numbers)
    queue = deque()
    queue.append((0, 0))  # (현재까지의 합, 현재 인덱스)
    answer = 0

    while queue:
        current_sum, idx = queue.popleft()

        # 숫자를 다 썼으면 target과 비교
        if idx == n:
            if current_sum == target:
                answer += 1
        else:
            # 다음 숫자를 더한 경우
            queue.append((current_sum + numbers[idx], idx + 1))
            # 다음 숫자를 뺀 경우
            queue.append((current_sum - numbers[idx], idx + 1))

    return answer
