import java.io.*;
import java.util.*;

public class 퇴사 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String[] s;
        int[][] arr = new int[N + 1][2];
        for (int i = 1; i <= N; i++) {
            s = br.readLine().split(" ");
            arr[i][0] = Integer.parseInt(s[0]);
            arr[i][1] = Integer.parseInt(s[1]);
        }
        int[] dp = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            int max = dp[i - 1];
            for (int j = 1; j <= i; j++) {
                if (arr[j][0] + j - 1 == i) {
                    max = Math.max(max, dp[j - 1] + arr[j][1]);
                }
            }
            dp[i] = max;
            //bw.write(Arrays.toString(dp) + "\n");
        }
        bw.write(dp[N] + "\n");
        bw.flush();
    }
}
