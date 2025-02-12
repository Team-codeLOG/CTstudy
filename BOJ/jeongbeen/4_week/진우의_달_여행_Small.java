import java.io.*;
import java.util.*;

public class 진우의_달_여행_Small {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int M = Integer.parseInt(s[1]);

        int[][][] dp = new int[N + 1][M + 2][3];
        int[][] arr = new int[N + 1][M + 1];
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M + 1; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            String[] ss = br.readLine().split(" ");
            for (int j = 1; j <= M; j++) {
                arr[i][j] = Integer.parseInt(ss[j - 1]);
            }
        }

        for (int j = 0; j <= M + 1; j++) {
            for (int k = 0; k < 3; k++) {
                dp[0][j][k] = 0;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = 0; k < 3; k++) {
                    int m;
                    if (k == 0) m = Math.min(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
                    else if (k == 1) m = Math.min(dp[i - 1][j - 1][2], dp[i - 1][j + 1][0]);
                    else m = Math.min(dp[i - 1][j + 1][0], dp[i - 1][j][1]);
                    dp[i][j][k] = m + arr[i][j];
                }
            }
        }

        int min = Integer.MAX_VALUE;
        for (int i = 1; i <= M; i++) {
            for (int k = 0; k < 3; k++) {
                min = Math.min(min, dp[N][i][k]);
            }
        }
        bw.write(min + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
