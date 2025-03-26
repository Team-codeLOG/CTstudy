const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n");

const n = parseInt(input[0], 10);
const used = new Set();

for (let i = 1; i <= n; i++) {
  const option = input[i];
  let markedIndex = -1;
  const optionChars = option.split("");

  // 각 단어의 첫 글자 인덱스를 수집
  const firstLetterIndices = [];
  for (let j = 0; j < option.length; j++) {
    if (j === 0 || option[j - 1] === " ") {
      firstLetterIndices.push(j);
    }
  }

  // 단어의 첫 ch 검증
  for (let idx of firstLetterIndices) {
    const ch = optionChars[idx];
    if (/[a-zA-Z]/.test(ch)) {
      const lowerCh = ch.toLowerCase();
      if (!used.has(lowerCh)) {
        markedIndex = idx;
        used.add(lowerCh);
        break;
      }
    }
  }

  // 단어의 첫 ch 제외하고 다른 ch 검증
  if (markedIndex === -1) {
    for (let j = 0; j < optionChars.length; j++) {
      const ch = optionChars[j];
      if (/[a-zA-Z]/.test(ch)) {
        const lowerCh = ch.toLowerCase();
        if (!used.has(lowerCh)) {
          markedIndex = j;
          used.add(lowerCh);
          break;
        }
      }
    }
  }

  if (markedIndex !== -1) {
    optionChars[markedIndex] = "[" + optionChars[markedIndex] + "]";
  }
  console.log(optionChars.join(""));
}
