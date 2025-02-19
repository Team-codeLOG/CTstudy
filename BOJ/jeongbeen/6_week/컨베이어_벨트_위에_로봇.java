import java.io.*;
import java.util.*;

public class 컨베이어_벨트_위에_로봇 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int K = Integer.parseInt(s[1]);
        int[] arr = new int[N * 2];
        int[] robot = new int[N * 2];
        int start = 0;
        int end = N - 1;
        s = br.readLine().split(" ");
        for (int i = 0; i < N * 2; i++) {
            arr[i] = Integer.parseInt(s[i]);
        }
        int count = 0;
        int step = 0;
        while (true) {
            start = (start + (N * 2) - 1) % (N * 2);
            end = (end + (N * 2) - 1) % (N * 2);
            if (robot[end] == 1) robot[end] = 0;
            for (int i = end > start ? end : end + (N * 2); i >= start; i--) {
                if ((i % (N * 2)) != end && robot[i % (N * 2)] == 1 && robot[(i + 1) % (N * 2)] == 0 && arr[(i + 1) % (N * 2)] > 0) {
                    robot[(i + 1) % (N * 2)] = 1;
                    if ((i + 1) % (N * 2) == end) robot[(i + 1) % (N * 2)] = 0;
                    robot[i % (N * 2)] = 0;
                    arr[(i + 1) % (N * 2)]--;
                    if (arr[(i + 1) % (N * 2)] == 0) count++;
                }
            }
            if (arr[start] > 0) {
                robot[start] = 1;
                arr[start]--;
                if (arr[start] == 0) count++;
            }
            step++;
//            bw.write("start: " + start + "\n");
//            bw.write("end: " + end + "\n");
//            bw.write("arr: " + Arrays.toString(arr) + "\n");
//            bw.write("robot: " + Arrays.toString(robot) + "\n");
//            bw.write("count: " + count + "\n");
            if (count >= K) break;
        }
        bw.write(step + "\n");
        bw.flush();
    }
}
