const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (input) => {
  const num = Number(input.trim());
  rl.close();
});

function solution(num) {
  const Q = Array.from({ length: num }, (v, i) => (v = i + 1));
  let idx = 0;

  while (idx !== Q.length - 1) {
    if (idx % 2 === 0) idx++;
    else Q.push(Q[idx++]);
  }

  return Q[idx];
}
