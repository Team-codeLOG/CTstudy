import java.io.*;
import java.util.*;

public class 카드2 {
     public static void main(String[] args) throws IOException {
         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

         int N = Integer.parseInt(br.readLine());

         Queue<Integer> queue = new LinkedList<>();

         for (int i = 1; i <= N; i++) {
             queue.add(i);
         }
         while (queue.size() > 1) {
             queue.poll();
             queue.add(queue.poll());
         }
         bw.write(queue.poll() + "\n");
         bw.flush();
     }
}
