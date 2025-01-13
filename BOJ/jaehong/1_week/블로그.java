import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 블로그 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String[] firstLine = br.readLine().split(" ");
    int N = Integer.parseInt(firstLine[0]);
    int X = Integer.parseInt(firstLine[1]);

    String[] secondLine = br.readLine().split(" ");

    int[] visitors = Arrays.stream(secondLine)
        .mapToInt(Integer::parseInt)
        .toArray();

    // 이중 for문으로 구현하기
    // for (int i = 0; i <= N - X; i++) {
    // int sum = 0;
    // for (int j = i; j < i + X; j++) {
    // sum += visitors[j];
    // }

    // if (sum > max) {
    // max = sum;
    // count = 1;
    // } else if (sum == max) {
    // count++;
    // }
    // }
    int sum = 0;
    for (int i = 0; i < X; i++) {
      sum += visitors[i];
    }

    int max = sum;
    int answer = 1;
    for (int i = 0; i < N - X; i++) {
      sum += visitors[i + X];
      sum -= visitors[i];

      if (sum == max) {
        answer++;
      }

      if (sum > max) {
        answer = 1;
        max = sum;
      }

    }

    // 결과값 정리하기
    if (max == 0) {
      System.out.println("SAD");
    } else {
      System.out.println(max);
      System.out.println(answer);
    }
  }
}
