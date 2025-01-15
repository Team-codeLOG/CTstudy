import java.io.*;
import java.util.HashSet;

public class 임스와함께하는미니게임 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] s = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int numOfPeople;
        HashSet<String> set = new HashSet<>();

        if (s[1].equals("Y")) numOfPeople = 1;
        else if (s[1].equals("F")) numOfPeople = 2;
        else numOfPeople = 3;

        for (int i = 0; i < N; i++) set.add(br.readLine());

        bw.write(Integer.toString(set.size() / numOfPeople));
        bw.flush();
        br.close();
        bw.close();
    }
}
