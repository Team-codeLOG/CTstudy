import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class 비슷한_단어 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // hashmap 말고 걍 배열로 바꾸기
        int answer = 0;
        int[] count = new int[26];
        ArrayList<String> words = new ArrayList<>();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            words.add(br.readLine());
        }

        for (int i = 0; i < words.get(0).length(); i++) {
            char ch = words.get(0).charAt(i);
            count[ch - 'A']++;
        }

        for (String word: words) {
            int[] temp = new int[26];

            for (int i = 0; i < word.length(); i++) {
                char ch = word.charAt(i);
                temp[ch - 'A']++;
            }
            
            int difference = 0;
            int hasDiff = 0;
            int isAnswer = 1;
            for (int i = 0; i < 26; i++) {
                int tempDiff = temp[i] - count[i];
                if (tempDiff != 0) {
                    if (hasDiff == 0) {
                        hasDiff = 1;
                        difference = tempDiff;
                    }
                    else if ((difference == -1 && tempDiff == 1) || (difference == 1 && tempDiff == -1)) difference = 0;
                    else {
                        isAnswer = 0;
                        break;
                    }
                }
            }
            if (isAnswer == 1) answer++;
        }

        answer -= 1;

        bw.write(answer + "\n");
        bw.flush();
        br.close();
        bw.close();
    }
}
