import java.util.*;
class Solver {
    int v;
    int adj[][];
    int color[];
    Solver(int n) {
        v = n;
        adj = new int[n][n];
        color = new int[n];
        int i, j;
        for (i = 0; i < n; i++) {
            color[i] = -1;
            for (j = 0; j < n; j++)
                adj[i][j] = 0;
        }
    }

    void add(int i, int j) {
        adj[i][j] = 1;
        adj[j][i] = 1;
    }

    boolean check(int src) {
        Queue<Integer> q = new ArrayDeque<Integer>();;
        q.add(src);
        while(q.peek() != null) {
            int x = q.remove();
            for (int i = 0; i < v; i++) {
                if (adj[x][i] == 1 && color[i] == -1) {
                    color[i] = 1 - color[x];
                    q.add(i);
                }
                else if (adj[x][i] == 1 && color[i] == color[x])
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int a = 1; a <= t; a++) {
            System.out.println("Scenario #"+a+":");
            int v = in.nextInt();
            int e = in.nextInt();
            Solver s = new Solver(v);
            for (int i = 0; i < e; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                s.add(x-1, y-1);
            }
            boolean ans = false;
            for (int i = 0; i < v; i++) {
                if (s.color[i] == -1) {
                    ans = s.check(i);
                    if (ans)
                        break;
                }
            }
            if (ans)
                System.out.println("No suspicious bugs found!");
            else
                System.out.println("Suspicious bugs found!");
        }
    }
}
