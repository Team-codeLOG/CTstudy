import java.util.Scanner;

public class 분수찾기 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int X = sc.nextInt();
    int n = 0;
    int top = 1;
    int bottom = 1;
    int count = 0;
    if (X == 1) {
      System.out.println("1/1");
    } else {
      while (count < X) {
        n++;
        count = n * (n + 1) / 2;
      }
      int num = X - (n - 1) * n / 2;
      if (n % 2 == 0) {
        top = num;
        bottom = n - num + 1;
      } else {
        top = n - num + 1;
        bottom = num;
      }
      System.out.println(top + "/" + bottom);
    }
  }
}