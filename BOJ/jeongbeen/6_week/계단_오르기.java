import java.io.*;
import java.util.*;

public class 계단_오르기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[301];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int[] dp = new int[301];
        dp[1] = arr[1];
        dp[2] = dp[1] + arr[2];
        dp[3] = Math.max(arr[1], arr[2]) + arr[3];
        for (int i = 4; i <= N; i++) {
            int max = 0;
            max = Math.max(dp[i - 3] + arr[i - 1], dp[i - 2]);
            dp[i] = max + arr[i];
        }
        bw.write(dp[N] + "\n");
        bw.flush();
    }
}
