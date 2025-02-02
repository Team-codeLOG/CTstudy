import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class 설탕_배달 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int answer = -1;
        for (int i = 0; i < 5; i++) {
            int x = n - (3 * i);
            if (x < 0) break;
            if (x % 5 == 0) {
                answer = i + x / 5;
                break;
            }
        }

        bw.write(answer + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
