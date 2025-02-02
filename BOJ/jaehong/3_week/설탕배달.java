package BOJ.jaehong.3_week;

import java.util.Scanner;

public class 설탕배달 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();

        int count = 0;
        while (n >= 0) {
            if (n % 5 == 0) {
                count += n / 5;
                System.out.println(count);
                return;
            }
            n -= 3;
            count++;
        }

        System.out.println(-1);
    }
}
