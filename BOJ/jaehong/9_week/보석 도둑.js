// max heap
class MaxHeap {
  constructor() {
    this.heap = [];
  }
  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }
  size() {
    return this.heap.length;
  }
  push(value) {
    this.heap.push(value);
    let idx = this.heap.length - 1;
    let parent = Math.floor((idx - 1) / 2);

    while (this.heap[parent] < value) {
      this.swap(parent, idx);
      idx = parent;
      parent = Math.floor((idx - 1) / 2);
    }
  }

  pop() {
    const lastIdx = this.heap.length - 1;
    let idx = 0;
    this.swap(0, lastIdx);
    let value = this.heap.pop();

    while (idx < lastIdx) {
      let leftChildIdx = idx * 2 + 1;
      let rightChildIdx = idx * 2 + 2;

      if (leftChildIdx >= lastIdx) {
        break;
      } else if (rightChildIdx >= lastIdx) {
        if (this.heap[idx] < this.heap[leftChildIdx]) {
          this.swap(idx, leftChildIdx);
          idx = leftChildIdx;
        } else {
          break;
        }
      } else {
        if (this.heap[leftChildIdx] > this.heap[idx] && this.heap[rightChildIdx] > this.heap[idx]) {
          if (this.heap[leftChildIdx] > this.heap[rightChildIdx]) {
            this.swap(idx, leftChildIdx);
            idx = leftChildIdx;
          } else {
            this.swap(idx, rightChildIdx);
            idx = rightChildIdx;
          }
        } else if (this.heap[leftChildIdx] > this.heap[idx]) {
          this.swap(leftChildIdx, idx);
          idx = leftChildIdx;
        } else if (this.heap[rightChildIdx] > this.heap[idx]) {
          this.swap(rightChildIdx, idx);
          idx = rightChildIdx;
        } else {
          break;
        }
      }
    }
    return value;
  }
}

const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "../input.txt")
  .toString()
  .trim()
  .split("\n")
  .map((v) => v.split(" ").map(Number));

function solution(input) {
  let totalValue = 0;
  const maxHeap = new MaxHeap();

  const [N, K] = input[0];

  // 가방과 보석 오름차순 정렬
  const jewels = input.slice(1, N + 1).sort((a, b) => a[0] - b[0]);

  const bags = input
    .slice(N + 1, N + 1 + K)
    .map(([capacity]) => capacity)
    .sort((a, b) => a - b);

  let jewelIndex = 0;

  for (let bagCapacity of bags) {
    while (jewelIndex < N && jewels[jewelIndex][0] <= bagCapacity) {
      maxHeap.push(jewels[jewelIndex][1]);
      jewelIndex++;
    }
    if (maxHeap.size()) {
      totalValue += maxHeap.pop();
    }
  }

  return totalValue;
}

console.log(solution(input));
