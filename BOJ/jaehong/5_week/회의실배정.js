const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N = 0;
let count = 0;
const meetings = [];

rl.on('line', function (line) {
  if (count === 0) {
    N = parseInt(line);
    count++;
  } else {
    const [start, end] = line.split(' ').map(Number);
    meetings.push([start, end]);

    if (meetings.length === N) {
      solution();
      rl.close();
    }
  }
});

function solution() {
  meetings.sort((a, b) => {
    if (a[1] === b[1]) {
      return a[0] - b[0];
    }
    return a[1] - b[1];
  });

  let count = 0;
  let endTime = 0;

  for (let i = 0; i < N; i++) {
    if (meetings[i][0] >= endTime) {
      endTime = meetings[i][1];
      count++;
    }
  }

  console.log(count);
}