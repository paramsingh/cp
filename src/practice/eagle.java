import java.io.*;
import java.util.*;

class Eagle {
    Node tree[];
    int n;

    private class Edge {
        long weight;
        Node target;
        long path;
        Edge(long n, Node x) {
            weight = n;
            target = x;
            path = -1;
        }
    }

    private class Node {
        int id;
        List<Edge> lst;
        int deg;

        Node(int i) {
            id = i;
            lst = new ArrayList<Edge>();
            deg = 0;
        }

        void add(long weight, Node x) {
            deg++;
            lst.add(new Edge(weight, x));
        }
    }

    Eagle(int x) {
        n = x;
        tree = new Node[n];
        int i;
        for (i = 0; i < n; i++) {
            tree[i] = new Node(i);
        }
    }

    public void add(int x, int y, long weight) {
        tree[x-1].add(weight, tree[y-1]);
        tree[y-1].add(weight, tree[x-1]);
    }

    public void solve() {
        int i;
        for (i = 0; i < n; i++) {
            System.out.print(path(tree[i], null) + " ");
        }
    }

    public long path(Node x, Node prev) {
        if (x.deg == 1 && prev != null) {
            return 0;
        }
        else {
            if (prev != null) {
                long a = -1;
                for (Edge e: x.lst) {
                    long cur = -1;
                    if (e.path == -1 && e.target.id != prev.id)
                        e.path = e.weight + path(e.target, x);
                    if (e.target.id != prev.id)
                        cur = e.path;
                    if (a < cur)
                        a = cur;
                }
                return a;
            }
            else {
                long a = -1;
                for (Edge e: x.lst) {
                    long cur = -1;
                    if (e.path == -1)
                        e.path = e.weight + path(e.target, x);
                    cur = e.path;
                    if (a < cur)
                        a = cur;
                }
                return a;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int t = Integer.parseInt(in.readLine());
        for (int cases = 0; cases < t; cases++) {
            int n = Integer.parseInt(in.readLine());
            int i;
            Eagle tree = new Eagle(n);
            for (i = 1; i < n; i++) {
                String s[] = in.readLine().split(" ");
                int x = Integer.parseInt(s[0]);
                int y = Integer.parseInt(s[1]);
                long z = Long.parseLong(s[2]);
                tree.add(x, y, z);
            }
            tree.solve();
            System.out.println();
        }
    }
}


