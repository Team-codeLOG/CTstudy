import java.io.*;
import java.util.*;

public class 포도주_시식 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[10005];
        int[] dp = new int[10005];

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        dp[0] = arr[0];
        dp[1] = arr[0] + arr[1];
        dp[2] = max3(dp[1], arr[1] + arr[2], arr[0] + arr[2]);
        for (int i = 3; i < N; i++) {
            dp[i] = max3(dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
        }

        bw.write(dp[N - 1] + "\n");
        bw.flush();
    }

    public static int max3(int a, int b, int c) {
        int max = Math.max(a, b);
        max = Math.max(max, c);
        return max;
    }
}
