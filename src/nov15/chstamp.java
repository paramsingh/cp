// Author: Param Singh <paramsingh258@gmail.com>
// Chef and collection of stamps: https://www.codechef.com/NOV15/problems/CHSTAMP

import java.util.*;
import java.io.*;

class Stamp {
    private class Edge {
        int day;
        int dest;
        Edge(int d, int des) {
            day = d;
            dest = des;
        }
    }

    private class Node {
        int val;
        List<Edge> adj;
        Map<Integer, Integer> max;
        Node(int i) {
            val = i;
            adj = new ArrayList<Edge>();
            max = new HashMap<Integer, Integer>();
        }

        void add(int day, int dest) {
            adj.add(new Edge(day, dest));
        }
    }

    Node nodes[];
    int maxd;

    Stamp() {
        nodes = new Node[50002];
        for (int i = 0; i < 50002; i++)
            nodes[i] = null;
        maxd = -1;
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

    void findmax() {
        int i;
        for (i = 0; i < 50002; i++) {
            if (nodes[i] != null && !nodes[i].max.containsKey(maxd)) {
                find(nodes[i], maxd);
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
            for (i = 0; i < m; i++) {
                int d = in.nextInt();
                int x = in.nextInt();
                int y = in.nextInt();
                graph.add(d, x, y);
                if (graph.maxd < d)
                    graph.maxd = d;
            }
        }
    }
}
