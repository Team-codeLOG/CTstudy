const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "BACKJOON_001446.txt";
const input = fs.readFileSync(filePath, "utf8").trim().split(/\r?\n/);

const [N, D] = input.shift().split(" ").map(Number);

const shortcuts = [];
input.forEach((line) => {
  const [start, end, time] = line.split(" ").map(Number);
  if (start > D || end > D) return;
  if (!shortcuts[start]) {
    shortcuts[start] = [];
  }
  shortcuts[start].push([end, time]);
});

const dp = Array.from({ length: D + 1 }, (_, i) => i);

for (let i = 0; i < D; i++) {
  dp[i + 1] = Math.min(dp[i + 1], dp[i] + 1);

  if (!shortcuts[i]) continue;
  shortcuts[i].forEach(([end, time]) => {
    dp[end] = Math.min(dp[end], dp[i] + time);
  });
}

console.log(dp[D]);
