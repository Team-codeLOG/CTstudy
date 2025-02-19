import java.io.*;
import java.util.*;

public class BOJ15989 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        int[] dp = new int[10001];
        int[] dp2 = new int[10001];
        dp2[2] = 1;
        dp2[3] = 1;
        for (int i = 4; i <= 10000; i++) {
            dp2[i] = dp2[i - 2];
            if (i % 3 == 0) dp2[i]++;
        }
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= 10000; i++) {
            dp[i] = dp[i - 1] + dp2[i];
        }
        for (int i = 0; i < T; i++) {
            int number = Integer.parseInt(br.readLine());
            bw.write(dp[number] + "\n");
        }
        bw.flush();
    }
}
