def solution(numbers, target):
	global answer
	answer = 0
	num_length = len(numbers)
	
	def dfs(i, curr_sum):
		if(i==num_length):
			if(curr_sum == target):
				global answer
				answer += 1
			return
		else:
			dfs(i+1, curr_sum + numbers[i])
			dfs(i+1, curr_sum - numbers[i])

	dfs(0, 0)
	return answer