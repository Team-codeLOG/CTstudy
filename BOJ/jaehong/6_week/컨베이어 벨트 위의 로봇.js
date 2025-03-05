const input = require('fs')
  .readFileSync(process.platform === 'linux' ? '/dev/stdin' : __dirname + '/example.txt')
  .toString().trim().split('\n').map(e => e.split(' ').map(Number));

const [n, k] = input.shift();
const belt = input.shift();
const robots = Array.from({ length: 2 * n }, () => false);
let stage = 0;

const check = () => {
  const val = belt.reduce((acc, cur) => acc + (cur === 0 ? 1 : 0), 0);
  return val
}

const rotate = () => {
  const temp = belt.pop();
  belt.unshift(temp);

  robots.pop();
  robots.unshift(false);
}

const remove = () => {
  robots[n - 1] = false;
}

const moveRo = () => {
  for (let i = n - 2; i > -1; i--){
    if (!robots[i]) continue;

    if (!robots[i + 1] && belt[i + 1] > 0) {
      robots[i] = false;
      robots[i + 1] = true;
      belt[i + 1] -= 1;
    }
  }
}

const add = () => {
  if (belt[0] > 0) {
    belt[0] -= 1;
    robots[0] = true;
  }
}

const solution = () => {

  while (check() < k) {
    stage++;

    rotate();
    if (robots[n - 1]) remove();

    moveRo();
    if (robots[n - 1]) remove();
    add();
  }
  console.log(stage)
}
solution();