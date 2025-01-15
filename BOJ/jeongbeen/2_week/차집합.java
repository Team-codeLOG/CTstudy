import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class 차집합 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int aLen = Integer.parseInt(st.nextToken());
        int bLen = Integer.parseInt(st.nextToken());
        ArrayList<Integer> a = new ArrayList<>();
        ArrayList<Integer> b = new ArrayList<>();
        ArrayList<Integer> inner = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < aLen; i++) a.add(Integer.parseInt(st.nextToken()));
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < bLen; i++) b.add(Integer.parseInt(st.nextToken()));

        a.sort(null);
        b.sort(null);
        int start = 0;
        for (int i = 0; i < bLen; i++) {
            int find = b.get(i);
            int end = a.size() - 1;
            int mid = 0;
            while (start <= end) {
                mid = (start + end) / 2;
                if (a.get(mid) < find) start = mid + 1;
                else if (a.get(mid) > find) end = mid - 1;
                else break;
            }
            if (a.get(mid) == find) {
                start = mid + 1;
                inner.add(find);
            }
            else start = 0;
        }

        start = 0;
        bw.write(a.size() - inner.size() + "\n");
        for (int i: a) {
            if (start < inner.size() && i == inner.get(start)) {
                start++;
            }
            else {
                bw.write(i + " ");
            }
        }

        bw.newLine();
        bw.flush();
        br.close();
        bw.close();
    }
}
