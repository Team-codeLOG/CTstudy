import java.io.*;

public class 햄버거_분배 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int K = Integer.parseInt(s[1]);
        int[] arr = new int[N];

        s = br.readLine().split("");
        for (int i = 0; i < N; i++) {
            if (s[i].equals("H")) arr[i] = 1;
            else arr[i] = 0;
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == 0) {
                for (int j = i - K; j <= i + K; j++) {
                    if (j < 0 || j >= N) continue;
                    if (arr[j] == 1) {
                        arr[j] = -1;
                        count++;
                        break;
                    }
                }
            }
        }
        bw.write(count + "\n");
        bw.flush();
    }
}
