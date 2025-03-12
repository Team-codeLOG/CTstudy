import java.io.*;
import java.util.*;

public class 게으른_백곰 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = new int[1000001];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int g = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            arr[x] = g;
        }
        int sum = 0;
        int i;
        for (i = 0; i < 2 * K + 1; i++) {
            if (i >= arr.length) break;
            sum += arr[i];
        }
        int max = sum;
        for (i = 0; i < arr.length - (2 * K + 1); i++) {
            sum -= arr[i];
            sum += arr[i + 2 * K + 1];
            if (sum > max) max = sum;
        }
        bw.write(max + "\n");
        bw.flush();
    }
}
