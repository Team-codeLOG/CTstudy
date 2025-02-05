import java.io.*;

public class 쿠키의_신체_측정 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][N];
        for (int i = 0; i < N; i++) {
            String[] s = br.readLine().split("");
            for (int j = 0; j < N; j++) {
                if (s[j].equals("_")) arr[i][j] = 0;
                else arr[i][j] = 1;
            }
        }

        int[] heart = new int[2];
        int findHeart = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 1) {
                    heart[0] = i + 1;
                    heart[1] = j;
                    findHeart = 1;
                    break;
                }
            }
            if (findHeart == 1) break;
        }
        bw.write((heart[0] + 1) + " " + (heart[1] + 1) + "\n");

        int x = 0, y = 0;
        int[][] direction = {{0, -1}, {0, 1}, {1, 0}};
        for (int[] d : direction) {
            int size = 0;
            x = heart[0];
            y = heart[1];
            while (true) {
                x += d[0];
                y += d[1];
                if (x >= N || x < 0 || y >= N || y < 0) break;
                if (arr[x][y] == 0) break;
                size++;
            }
            bw.write(size + " ");
        }

        int size = 0;
        int left_x = x, left_y = y - 1;
        int right_x = x, right_y = y + 1;
        while (true) {
            size++;
            left_x += 1;
            if (left_x >= N) break;
            if (arr[left_x][left_y] == 0) break;
        }
        bw.write(size + " ");
        size = 0;
        while (true) {
            size++;
            right_x += 1;
            if (right_x >= N) break;
            if (arr[right_x][right_y] == 0) break;
        }
        bw.write(size + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
