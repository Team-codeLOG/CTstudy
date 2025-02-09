import java.util.*;
import java.io.*;

public class 분수찾기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int X = Integer.parseInt(br.readLine());
        int a;

        int count;
        int sum = 0;
        for (count = 1; true; count++) {
            sum += count;
            if (X <= sum) {
                break;
            }
        }
        if (count % 2 == 0) {
            a = 1;
            a += X - (sum - count + 1);
        }
        else {
            a = count;
            a -= X - (sum - count + 1);
        }
        bw.write(a + "/" + (count + 1 - a) + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
