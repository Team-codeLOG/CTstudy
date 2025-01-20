import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class 차집합 {
  public static void main(String[] args) throws IOException {
    BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

    String[] ABSize = bufferedReader.readLine().split(" ");
    String[] setStrA = bufferedReader.readLine().split(" ");
    String[] setStrB = bufferedReader.readLine().split(" ");

    HashSet<Integer> setNumA = new HashSet<>();
    HashSet<Integer> setNumB = new HashSet<>();

    for (String num : setStrA) {
      setNumA.add(Integer.parseInt(num));
    }

    for (String num : setStrB) {
      setNumB.add(Integer.parseInt(num));
    }

    setNumA.removeAll(setNumB); // 핵심

    System.out.println(setNumA.size());
    setNumA.stream().sorted().forEach(num -> System.out.print(num + " "));
  }
}
