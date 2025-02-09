package BOJ.jaehong.4_week;

import java.io.*;
import java.util.PriorityQueue;

public class 최소힙 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();

    for (int i = 0; i < N; i++) {
      int x = Integer.parseInt(br.readLine());

      if (x == 0) {
        if (minHeap.isEmpty()) {
          System.out.println(0);
        } else {
          System.out.println(minHeap.poll());
        }
      } else {
        minHeap.add(x);
      }
    }

    br.close();
  }
}
