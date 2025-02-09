import java.util.*;
import java.io.*;

public class 회의실_배정 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            String[] s = br.readLine().split(" ");
            ArrayList<Integer> list1 = new ArrayList<>();
            list1.add(Integer.parseInt(s[0]));
            list1.add(Integer.parseInt(s[1]));
            list.add(list1);
        }
        list.sort(Comparator.comparing((ArrayList<Integer> a) -> a.get(1)).thenComparing(a -> a.get(0)));
        Queue<ArrayList<Integer>> queue = new LinkedList<>();
        queue.addAll(list);
        int count = 0;
        int nowTime = 0;
        while (!queue.isEmpty()) {
            ArrayList<Integer> temp = queue.poll();
            int start = temp.get(0);
            int end = temp.get(1);
            if (start < nowTime) continue;
            count++;
            nowTime = end;
        }
        bw.write(count + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
