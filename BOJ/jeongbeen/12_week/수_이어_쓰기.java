import java.io.*;

public class 수_이어_쓰기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String numList = br.readLine();
        long num = 1L;
        int digit = 1;
        long digitNum = 10L;
        while (true) {
            String now = numList.substring(0, 1);
            long divide = 1L;
            for (int i = 1; i < digit; i++) {
                divide *= 10;
            }
            for (int i = 0; i < digit; i++) {
                long nowdigit = (num % (divide * 10)) / divide;
                if (nowdigit == Long.parseLong(now)) {
                    numList = numList.substring(1);
                    if (numList.isEmpty()) break;
                    now = numList.substring(0, 1);
                }
                divide /= 10;
            }
            if (numList.isEmpty()) break;
            num++;
            if (num >= digitNum) {
                digit++;
                digitNum *= 10;
            }
        }
        bw.write(num + "\n");
        bw.flush();
    }
}
