const fs = require("fs");
const input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map((line) => line.split(" ").map(Number));

const [N, K] = input.shift();
const coord = input;

function solution(K, coord) {
  let maxPosition = 0;
  const arr = Array(1000001).fill(0);

  for (const [ice, position] of coord) {
    arr[position] = ice;
    maxPosition = Math.max(maxPosition, position);
  }

  let windowSum = 0;
  for (let i = 0; i <= K && i <= maxPosition; i++) {
    windowSum += arr[i];
  }

  let maxIce = windowSum;
  for (let j = 0; j <= maxPosition; j++) {
    const left = j - K - 1;
    const right = j + K + 1;
    if (left >= 0) windowSum -= arr[left];
    if (right <= maxPosition) windowSum += arr[right];
    maxIce = Math.max(maxIce, windowSum);
  }

  return maxIce;
}

console.log(solution(K, coord));
