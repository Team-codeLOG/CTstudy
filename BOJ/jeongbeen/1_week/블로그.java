import java.io.*;
import java.util.ArrayList;

public class 블로그{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int X = Integer.parseInt(s[1]);
        ArrayList<Integer> list = new ArrayList<>();
        int sum = 0;
        int max = 0;
        int maxCount = 1;

        s = br.readLine().split(" ");
        for (int i = 0; i < N; i++) list.add(Integer.parseInt(s[i]));

        int front = 0;
        int rear = 0;
        for (rear = 0; rear < X; rear++) sum += list.get(rear);
        max = sum;

        for (rear = X; rear < N; rear++) {
            sum += list.get(rear) - list.get(front);
            front++;
            if (sum > max) {
                max = sum;
                maxCount = 1;
            }
            else if (sum == max) maxCount++;
        }

        if (max == 0) {
            bw.write("SAD");
            bw.flush();
            br.close();
            bw.close();
            return;
        }

        bw.write(Integer.toString(max));
        bw.newLine();
        bw.write(Integer.toString(maxCount));
        bw.flush();
        br.close();
        bw.close();
    }
}
