const filePath = process.platform === 'linux' ? '/dev/stdin' : 'e.txt';
const input = require('fs')
	.readFileSync(filePath)
	.toString()
	.trim()
	.split('\n')
	.map(Number);

const stairCount = input.shift();

const dp = new Array(stairCount).fill(0);

dp[0] = input[0];
dp[1] = Math.max(input[0] + input[1], input[1]);
dp[2] = Math.max(input[1], input[0]) + input[2];

for (let i = 3; i < input.length; i++) {
	dp[i] = Math.max(dp[i - 3] + input[i - 1], dp[i - 2]) + input[i];
}

console.log(dp[input.length - 1]);