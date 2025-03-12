import java.io.*;
import java.util.*;

public class 빗물 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int H = Integer.parseInt(s[0]);
        int W = Integer.parseInt(s[1]);
        int[] arr = new int[W];

        s = br.readLine().split(" ");
        for (int i = 0; i < W; i++) {
            arr[i] = Integer.parseInt(s[i]);
        }

        int max = 0;
        int maxIndex = 0;
        int i;
        for (i = 0; i < W; i++) {
            if (arr[i] > max) {
                max = arr[i];
                maxIndex = i;
            }
        }

        int localMax = 0;
        int water = 0;
        for (i = 0; i <= maxIndex; i++) {
            if (arr[i] >= localMax) {
                localMax = arr[i];
            }
            else {
                water += localMax - arr[i];
            }
        }
        localMax = 0;
        for (i = W - 1; i >= maxIndex; i--) {
            if (arr[i] >= localMax) {
                localMax = arr[i];
            }
            else {
                water += localMax - arr[i];
            }
        }

        bw.write(water + "\n");
        bw.flush();
    }
}
