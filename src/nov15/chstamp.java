import java.util.*;
import java.io.*;

class Stamp {
    private class Edge {
        int day;
        int dest;
        int max;
        Edge(int d, int des) {
            day = d;
            dest = des;
            max = 0;
        }
    }

    private class Node {
        int val;
        List<Edge> adj;
        int max;
        Node(int i) {
            val = i;
            adj = new ArrayList<Edge>();
            max = 0;
        }

        void add(int day, int dest) {
            adj.add(new Edge(day, dest));
        }
    }

    Node nodes[];
    int max;
    boolean visited[];

    Stamp() {
        nodes = new Node[50002];
        visited = new boolean[50002];
        for (int i = 0; i < 50002; i++) {
            nodes[i] = null;
            visited[i] = false;
        }
    }

    void add(int day, int x, int y) {
        if (nodes[x] == null && nodes[y] == null) {
            nodes[x] = new Node(x);
            nodes[y] = new Node(y);
        }
        else if (nodes[x] == null)
            nodes[x] = new Node(x);
        else if (nodes[y] == null)
            nodes[y] = new Node(y);
        nodes[x].add(day, y);
        nodes[y].add(day, x);
    }

    static class Offer implements Comparable<Offer> {
        int day, x, y;
        Offer(int day, int x, int y) {
            this.day = day;
            this.x = x;
            this.y = y;
        }

        public int compareTo(Offer o) {
            if (this.day != o.day)
                return this.day - o.day;
            else {
                if (this.x != o.x)
                    return this.x - o.x;
                else
                    return this.y - o.y;
            }
        }
    }

    void solve() {
        int i;
        for (i = max; i >= 0; i--) {
            if (nodes[i] != null) {
                dfs(i, i, 50005);
            }
        }
    }

    void dfs(int i, int prop, int day) {
        if (!visited[i]) {
            visited[i] = true;
            nodes[i].max = prop;
        }
        for (Edge e: nodes[i].adj) {
            if (e.day > day)
                break;
            else {
                if (e.max < prop) {
                    e.max = prop;
                    dfs(e.dest, prop, e.day);
                }
            }
        }
    }

    void print() {
        int i;
        for (i = 1; i < max; i++) {
            if (nodes[i] != null) {
                System.out.println(i + " -> " + nodes[i].max);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int cases = 0; cases < t; cases++) {
            int n = in.nextInt();
            int m = in.nextInt();
            Stamp graph = new Stamp();
            int stamps[] = new int[n];
            int i, j;
            for (i = 0; i < n; i++) {
                stamps[i] = in.nextInt();
            }
            Offer o[] = new Offer[m];
            int max = -1;
            for (i = 0; i < m; i++) {
                int d = in.nextInt();
                int x = in.nextInt();
                int y = in.nextInt();
                if (max < x)
                    max = x;
                if (max < y)
                    max = y;
                o[i] = new Offer(d, x, y);
            }
            graph.max = max;
            Arrays.sort(o);
            for (i = 0; i < m; i++) {
                graph.add(o[i].day, o[i].x, o[i].y);
            }
            graph.solve();
            graph.print();
            long sum = 0;
            for (i = 0; i < n; i++) {
                if (graph.nodes[stamps[i]] != null)
                    sum += graph.nodes[stamps[i]].max;
                else
                    sum += stamps[i];
            }
            System.out.println(sum);
        }
    }
}
