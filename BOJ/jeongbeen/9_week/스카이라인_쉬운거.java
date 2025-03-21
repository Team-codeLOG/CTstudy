import java.io.*;
import java.util.*;

public class 스카이라인_쉬운거 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        int buildings = 0;
        for (int i = 0; i < n; i++) {
            String[] s = br.readLine().split(" ");
            int now = Integer.parseInt(s[0]);
            int h = Integer.parseInt(s[1]);
            if (h != 0 && (pq.isEmpty() || h > pq.peek())) {
                pq.add(h);
            }
            else {
                while (!pq.isEmpty() && pq.peek() > h) {
                    //bw.write(now + " " + pq.peek() + "\n");
                    pq.remove();
                    buildings++;
                }
                if (h != 0 && (pq.isEmpty() || h > pq.peek())) {
                    pq.add(h);
                }
            }
        }
        while (!pq.isEmpty()) {
            pq.remove();
            buildings++;
        }
        bw.write(buildings + "\n");
        bw.flush();
    }
}
