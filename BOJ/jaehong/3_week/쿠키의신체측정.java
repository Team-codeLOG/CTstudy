package BOJ.jaehong.3_week;

import java.io.*;

public class 쿠키의신체측정 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    char[][] board = new char[n][n];

    // 입력받기
    for (int i = 0; i < n; i++) {
      board[i] = br.readLine().toCharArray();
    }

    // 심장 찾기
    int heartRow = 0, heartCol = 0;
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (board[i][j] == '*' && board[i - 1][j] == '*' && board[i + 1][j] == '*'
            && board[i][j - 1] == '*' && board[i][j + 1] == '*') {
          heartRow = i;
          heartCol = j;
          break;
        }
      }
    }

    // 왼팔
    int leftArm = 0;
    for (int j = heartCol - 1; j >= 0 && board[heartRow][j] == '*'; j--)
      leftArm++;

    // 오른팔
    int rightArm = 0;
    for (int j = heartCol + 1; j < n && board[heartRow][j] == '*'; j++)
      rightArm++;

    int waist = 0; // 허리 길이
    for (int i = heartRow + 1; i < n && board[i][heartCol] == '*'; i++)
      waist++;

    int waistEnd = heartRow + waist;

    int leftLeg = 0;
    for (int i = waistEnd + 1; i < n && board[i][heartCol - 1] == '*'; i++)
      leftLeg++;

    int rightLeg = 0;
    for (int i = waistEnd + 1; i < n && board[i][heartCol + 1] == '*'; i++)
      rightLeg++;

    System.out.println((heartRow + 1) + " " + (heartCol + 1));
    System.out.println(leftArm + " " + rightArm + " " + waist + " " + leftLeg + " " + rightLeg);
  }
}