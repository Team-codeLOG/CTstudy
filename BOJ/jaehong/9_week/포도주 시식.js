const fs = require("fs");
let [n, ...arr] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

arr = arr.map(Number);
n = Number(n);

const dp = new Array(n).fill(0);

dp[0] = arr[0];
if (n > 1) dp[1] = arr[0] + arr[1];
if (n > 2) dp[2] = Math.max(dp[1], arr[0] + arr[2], arr[1] + arr[2]);

for (let i = 3; i < n; i++) {
  dp[i] = Math.max(
    dp[i - 1], // 이번 잔을 안 마심
    dp[i - 2] + arr[i], // 이번 잔 마시고 전 잔을 안 마심
    dp[i - 3] + arr[i - 1] + arr[i] // 이번 잔과 전 잔 마시고 전전 잔을 안 마심
  );
}

console.log(dp[n - 1]);
