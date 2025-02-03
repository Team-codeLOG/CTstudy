import java.io.*;
import java.util.*;

public class 최소_힙 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            int number = Integer.parseInt(br.readLine());
            if (number == 0) {
                if (pq.isEmpty()) bw.write("0\n");
                else bw.write(pq.poll() + "\n");
            }
            else {
                pq.add(number);
            }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}
