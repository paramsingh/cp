// Author: Param Singh <paramsingh258@gmail.com>
// PARADOX: http://www.spoj.com/problems/PARADOX/

import java.io.*;
import java.util.*;

class Paradox {
    private class Node {
        int val;
        int inval;
        int index;
        List<Node> t;
        int num;
        List<Node> f;
        Node(int i) {
            val = -1;
            inval = -1;
            index = i;
            t = new ArrayList<Node>();
            f = new ArrayList<Node>();
            num = 0;
        }

        void add_true(Node x) {
            t.add(x);
            num++;
        }

        void add_false(Node x) {
            f.add(x);
            num++;
        }
    }

    Node nodes[];
    Paradox(int n) {
        nodes = new Node[n];
        for (int i = 0; i < n; i++)
            nodes[i] = new Node(i);
    }

    boolean dfs(Node x, int expected, boolean first) {
        if (x.val == -1 || first)
            x.val = expected;
        else {
            return (x.val != expected);
        }
        int nexp;
        for (Node node: x.t) {
            nexp = x.val;
            if (dfs(node, nexp, false))
                return true;
        }
        for (Node node: x.f) {
            nexp = 1 - x.val;
            if (dfs(node, nexp, false))
                return true;
        }
        return false;
    }


    boolean isParadox() {
        for (Node n: nodes) {
            if (n.val == -1 && n.num != 1) {
                boolean x = dfs(n, 1, true);
                boolean y = dfs(n, 0, true);
                if (!x && !y)
                    dfs(n, 1, true);
                else if (!x)
                    dfs(n, 1, true);
                else if (!y)
                    dfs(n, 0, true);
                else
                    return true;
            }
        }
        return false;
    }

    void add(int i, int n, boolean x) {
        if (x) {
            nodes[i].add_true(nodes[n]);
        }
        else {
            nodes[i].add_false(nodes[n]);
        }
        nodes[n].num++;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        while (n != 0) {
            Paradox p = new Paradox(n);
            for (int i = 0; i < n; i++) {
                int dest = in.nextInt();
                boolean x = in.next().equals("true");
                p.add(i, dest-1, x);
            }
            if (p.isParadox())
                System.out.println("PARADOX");
            else
                System.out.println("NOT PARADOX");
            n = in.nextInt();
        }
    }
}
