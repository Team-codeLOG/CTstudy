import java.util.*;
import java.io.*;

public class 배열_복원하기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int H = Integer.parseInt(s[0]);
        int W = Integer.parseInt(s[1]);
        int X = Integer.parseInt(s[2]);
        int Y = Integer.parseInt(s[3]);

        int[][] arrB = new int[H + X][W + Y];
        for (int i = 0; i < H + X; i++) {
            s = br.readLine().split(" ");
            for (int j = 0; j < W + Y; j++) {
                arrB[i][j] = Integer.parseInt(s[j]);
            }
        }

        int[][] arr = new int[H][W];
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < X || j < Y) {
                    arr[i][j] = arrB[i][j];
                }
                else {
                    arr[i][j] = arrB[i][j] - arr[i - X][j - Y];
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                bw.write(arr[i][j] + " ");
            }
            bw.newLine();
        }
        bw.flush();
    }
}
