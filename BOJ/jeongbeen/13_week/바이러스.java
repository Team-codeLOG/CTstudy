import java.io.*;
import java.util.*;

public class 바이러스2 {
    public static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        parent = new int[N];
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            String[] s = br.readLine().split(" ");
            int node1 = Integer.parseInt(s[0]) - 1;
            int node2 = Integer.parseInt(s[1]) - 1;
            union(node1, node2);
        }
        int answer = 0;
        for (int i = 0; i < N; i++) {
            if (getParent(i) == 0) answer++;
        }
        bw.write((answer - 1) + "\n");
        bw.flush();
    }

    public static int getParent(int node) {
        while (node != parent[node]) {
            node = parent[node];
        }
        return node;
    }

    public static void union(int node1, int node2) {
        int p1 = getParent(node1);
        int p2 = getParent(node2);

        if (p1 == p2) return;
        if (p1 < p2) parent[p2] = p1;
        else parent[p1] = p2;
    }
}
