import java.io.*;
import java.util.*;

public class 비슷한단어 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());

    String[] words = new String[n];
    for (int i = 0; i < n; i++) {
      words[i] = br.readLine();
    }

    int count = 0;
    String firstWord = words[0];

    for (int i = 1; i < n; i++) {
      if (isSimilar(firstWord, words[i])) {
        count++;
      }
    }

    System.out.println(count);
  }

  // 두 단어가 비슷한지 확인
  private static boolean isSimilar(String word1, String word2) {
    if (sameComposition(word1, word2)) {
      return true;
    }

    if (Math.abs(word1.length() - word2.length()) > 1) {
      return false;
    }

    if (word1.length() != word2.length()) {
      return canAddRemoveOne(word1, word2);
    }

    return canReplaceOne(word1, word2);
  }

  // 같은 구성인지 확인 후 true false 반환
  private static boolean sameComposition(String word1, String word2) {
    if (word1.length() != word2.length()) {
      return false;
    }

    int[] count1 = new int[26];
    int[] count2 = new int[26];

    for (char c : word1.toCharArray()) {
      count1[c - 'A']++;
    }
    for (char c : word2.toCharArray()) {
      count2[c - 'A']++;
    }

    return Arrays.equals(count1, count2);
  }

  // 같은 구성인데, 같은 알파벳 하나 추가 혹은 빼거나
  private static boolean canAddRemoveOne(String word1, String word2) {
    String shorter = word1.length() < word2.length() ? word1 : word2;
    String longer = word1.length() < word2.length() ? word2 : word1;

    int[] countShorter = new int[26];
    int[] countLonger = new int[26];

    for (char c : shorter.toCharArray()) {
      countShorter[c - 'A']++;
    }
    for (char c : longer.toCharArray()) {
      countLonger[c - 'A']++;
    }

    int diff = 0;
    for (int i = 0; i < 26; i++) {
      if (Math.abs(countShorter[i] - countLonger[i]) > 1) {
        return false;
      }
      if (countShorter[i] != countLonger[i]) {
        diff++;
      }
    }

    return diff == 1;
  }

  // 알파벳 하나가 다름
  private static boolean canReplaceOne(String word1, String word2) {
    int diff = 0;
    int[] count1 = new int[26];
    int[] count2 = new int[26];

    for (int i = 0; i < word1.length(); i++) {
      count1[word1.charAt(i) - 'A']++;
      count2[word2.charAt(i) - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
      if (count1[i] != count2[i]) {
        diff += Math.abs(count1[i] - count2[i]);
      }
    }

    return diff == 2;
  }
}