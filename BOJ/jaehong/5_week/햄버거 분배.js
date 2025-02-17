const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on("line", (line) => {
  input.push(line);

  if (input.length === 2) {
    const [N, K] = input[0].split(" ").map(Number);
    const arr = input[1].split("");

    // console.log(N,K,arr);

    console.log(solution(N, K, arr));
    rl.close();
  }
});

function solution(N, K, arr) {
  let people = [];
  let burgers = [];

  for (let i = 0; i < N; i++) {
    if (arr[i] === 'P') {
      people.push(i);
    } else if (arr[i] === 'H') {
      burgers.push(i);
    }
  }

  let count = 0;
  let pIndex = 0, hIndex = 0;

  while (pIndex < people.length && hIndex < burgers.length) {
    if (Math.abs(people[pIndex] - burgers[hIndex]) <= K) {
      count++;
      pIndex++;
      hIndex++;
    } else if (people[pIndex] < burgers[hIndex]) {
      pIndex++;
    } else {
      hIndex++;
    }
  }

  return count;
}
