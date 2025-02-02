import java.io.*;
import java.util.*;

public class 주식 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());
    for (int t = 0; t < T; t++) {
      st = new StringTokenizer(br.readLine());
      int N = Integer.parseInt(st.nextToken());
      int[] arr = new int[N];
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < N; i++) {
        arr[i] = Integer.parseInt(st.nextToken());
      }
      long sum = 0;
      int target = arr[N - 1];
      for (int i = N - 2; i >= 0; i--) {
        if (arr[i] <= target)
          sum += target - arr[i];
        else
          target = arr[i];
      }
      System.out.println(sum);
    }
  }
}