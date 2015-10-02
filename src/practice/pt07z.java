import java.util.*;
import java.io.*;
class Tree {
    private class Node {
        int num;
        int index;
        List<Node> adjacent;
        Node(int x) {
            num = 0;
            index = x;
            adjacent = new ArrayList<Node>();
        }
        void add(Node a) {
            adjacent.add(a);
            num++;
        }
    }
    Node nodes[];
    Tree(int n) {
        nodes = new Node[n];
        for (int i = 0; i < n; i++)
            nodes[i] = new Node(i);
    }

    int[] longest(Node src, Node prev) {
        if (src.num == 1 && prev != null) {
            int a[] = {0, src.index};
            return a;
        }
        else {
            int max = -1;
            int v = -1;
            for (Node x: src.adjacent) {
                if (x != prev) {
                    int a[] = longest(x, src);
                    int y = 1 + a[0];
                    if (y > max) {
                        max = y;
                        v = a[1];
                    }
                }
            }
            int a[] = {max, v};
            return a;
        }
    }

    int longest() {
        int v = longest(nodes[0], null)[1];
        return longest(nodes[v], null)[0];
    }

    void add(int x, int y) {
        nodes[x].add(nodes[y]);
        nodes[y].add(nodes[x]);
    }

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int n = Integer.parseInt(in.readLine());
        Tree t = new Tree(n);
        for (int i = 0; i < n-1; i++) {
            String s[] = in.readLine().split(" ");
            int x = Integer.parseInt(s[0]);
            int y = Integer.parseInt(s[1]);
            t.add(x-1, y-1);
        }
        System.out.println(t.longest());
    }
}
