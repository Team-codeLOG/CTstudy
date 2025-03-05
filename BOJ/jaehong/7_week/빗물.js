const filePath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";
const input = require("fs").readFileSync(filePath).toString().trim().split("\n");

const [H, W] = input[0].split(" ").map(Number);
const map = input[1].split(" ").map(Number);
let answer = 0;

for (let i = 1; i < W - 1; i++) {
  let left = 0;
  let right = 0;

  for (let j = 0; j < i; j++) left = Math.max(left, map[j]);
  for (let j = i + 1; j < W; j++) right = Math.max(right, map[j]);

  const target = Math.min(left, right) - map[i];

  if (target > 0) answer += target;
}

console.log(answer);
