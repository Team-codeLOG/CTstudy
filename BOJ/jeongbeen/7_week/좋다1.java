import java.io.*;
import java.util.*;

public class 좋다1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int good = 0;
        for (int i = 0; i < N; i++) {
            int left = 0;
            int right = N - 1;
            while (left < right) {
                if (left == i) {
                    left++;
                    continue;
                }
                if (right == i) {
                    right--;
                    continue;
                }
                if (arr[i] < arr[left] + arr[right]) right--;
                else if (arr[i] > arr[left] + arr[right]) left++;
                else {
                    good++;
                    break;
                }
            }
        }
        bw.write(good + "\n");
        bw.flush();
    }
}
