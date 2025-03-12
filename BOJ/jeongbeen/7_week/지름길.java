import java.io.*;
import java.util.*;

public class 지름길 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int D = Integer.parseInt(s[1]);

        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String[] ss = br.readLine().split(" ");
            ArrayList<Integer> list = new ArrayList<>();
            for (int j = 0; j < ss.length; j++) {
                list.add(Integer.parseInt(ss[j]));
            }
            if (list.get(1) <= D && (list.get(1) - list.get(0) - list.get(2) > 0)) arr.add(list);
        }

        int[] dist = new int[D + 1];
        for (int i = 1; i <= D; i++) {
            int min = dist[i - 1] + 1;
            for (ArrayList<Integer> list : arr) {
                if (list.get(1) == i) {
                    min = Math.min(dist[list.get(0)] + list.get(2), min);
                }
            }
            dist[i] = min;
        }
        bw.write(dist[D] + "\n");
        bw.flush();
    }
}
