import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class 임스와_함께하는_미니게임 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] infoLine = br.readLine().split(" ");
        int members = Integer.parseInt(infoLine[0]);
        String gameType = infoLine[1];

        Set<String> nameSet = new HashSet<>();
        for (int i = 0; i < members; i++) {
            nameSet.add(br.readLine());
        }

        int playersPerGame = 0;
        switch (gameType) {
            case "Y":
                playersPerGame = 2;
                break;
            case "F":
                playersPerGame = 3;
                break;
            case "O":
                playersPerGame = 4;
                break;
            default:
                System.out.println("Invalid game type");
                return;
        }
        int answer = nameSet.size() / (playersPerGame - 1);
        System.out.println(answer);
    }
}
