import java.io.*;
import java.util.*;

public class 근손실 {
    public static int K;
    public static int N;
    public static int[] kit;
    public static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        N = Integer.parseInt(s[0]);
        K = Integer.parseInt(s[1]);

        kit = new int[N];
        int[] check = new int[N];
        s = br.readLine().split(" ");
        for (int i = 0; i < N; i++) {
            kit[i] = Integer.parseInt(s[i]);
        }
        dfs(0, 500, check);
        bw.write(count + "\n");
        bw.flush();
    }

    public static void dfs(int cnt, int nowNum, int[] check) {
        if (cnt == N) {
            count++;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (check[i] == 1) continue;
            int newNum = nowNum + kit[i] - K;
            if (newNum < 500) continue;
            check[i] = 1;
            dfs(cnt + 1, newNum, check);
            check[i] = 0;
        }
    }
}
