import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;

public class 주식 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            String[] s = br.readLine().split(" ");
            int[] arr = new int[N];
            for (int j = 0; j < N; j++) {
                arr[j] = Integer.parseInt(s[j]);
            }

            int assending = 0;
            long own = 0;
            int max = 0;
            for (int j = N - 1; j >= 0; j--) {
                if (max < arr[j]) {
                    own += (long) assending * max;
                    max = arr[j];
                    assending = 0;
                }
                else {
                    own -= arr[j];
                    assending++;
                }
                //bw.write("own:" + own + "\n");
            }
            own += (long) assending * max;
            bw.write(own + "\n");
        }
        bw.flush();
        br.close();
        bw.close();
    }
}
