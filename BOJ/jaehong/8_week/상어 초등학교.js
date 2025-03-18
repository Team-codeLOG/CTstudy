const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = parseInt(input[0]);
const students = input.slice(1).map((line) => line.split(" ").map(Number));

console.log(sharkElementarySchool(N, students));

function sharkElementarySchool(N, students) {
  // 1. 교실 초기화
  let classroom = Array.from({ length: N }, () => Array(N).fill(0));

  // 2. 학생별 좋아하는 학생 저장
  let studentMap = new Map();
  students.forEach(([num, ...likes]) => {
    studentMap.set(num, new Set(likes));
  });

  // 3. 이동 방향 (상, 하, 좌, 우)
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  // 4. 자리 배치
  students.forEach(([num, ...likes]) => {
    let bestPositions = [];
    let maxLike = -1; // 좋아하는 학생 인접 수 최대값
    let maxEmpty = -1; // 빈 칸 개수 최대값

    for (let r = 0; r < N; r++) {
      for (let c = 0; c < N; c++) {
        if (classroom[r][c] !== 0) continue; // 이미 자리 차있음

        let likeCount = 0;
        let emptyCount = 0;

        for (let i = 0; i < 4; i++) {
          let nr = r + dx[i];
          let nc = c + dy[i];

          if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
            if (studentMap.get(num).has(classroom[nr][nc])) {
              likeCount++;
            } else if (classroom[nr][nc] === 0) {
              emptyCount++;
            }
          }
        }

        // 조건 우선순위 결정
        if (likeCount > maxLike || (likeCount === maxLike && emptyCount > maxEmpty)) {
          bestPositions = [[r, c]];
          maxLike = likeCount;
          maxEmpty = emptyCount;
        } else if (likeCount === maxLike && emptyCount === maxEmpty) {
          bestPositions.push([r, c]);
        }
      }
    }

    // 3번 조건 (행/열 기준 정렬)
    bestPositions.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
    let [selectedR, selectedC] = bestPositions[0];
    classroom[selectedR][selectedC] = num;
  });

  // 5. 만족도 계산
  let totalSatisfaction = 0;
  const satisfactionMap = [0, 1, 10, 100, 1000];

  for (let r = 0; r < N; r++) {
    for (let c = 0; c < N; c++) {
      let studentNum = classroom[r][c];
      let likes = studentMap.get(studentNum);

      let likeCount = 0;
      for (let i = 0; i < 4; i++) {
        let nr = r + dx[i];
        let nc = c + dy[i];

        if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
          if (likes.has(classroom[nr][nc])) {
            likeCount++;
          }
        }
      }

      totalSatisfaction += satisfactionMap[likeCount];
    }
  }

  return totalSatisfaction;
}
