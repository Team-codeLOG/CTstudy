from collections import deque

def solution(numbers, target):
    
    def dfs(idx, current_sum):
        
        if idx == len(numbers):# idx가 numbers의 길이에 도달하면(모든 숫자를 다 처리했으면)
            return 1 if current_sum == target else 0 # 현재까지의 합 current_sum이 target과 같으면 1을 반환, 아니면 0을 반환
        
        #현재 숫자를 더하는 경우 - dfs(idx + 1, current_sum + numbers[idx])
        #현재 숫자를 빼는 경우 - dfs(idx + 1, current_sum - numbers[idx])
        return dfs(idx + 1, current_sum + numbers[idx]) + dfs(idx + 1, current_sum - numbers[idx])

    return dfs(0, 0)
