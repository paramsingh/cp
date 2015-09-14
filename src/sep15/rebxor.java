// SUBXOR, for practicing tries
import java.util.Scanner;
class Trie {
    private class Node {
        int val;
        Node children[] = new Node[2];
        Node() {
            val = -1;
            children[0] = null;
            children[1] = null;
        }
    }

    private Node root;

    public Trie() {
        root = new Node();
        addNumber(root, 0, 32, -1);
    }

    private void addNumber(Node vertex, int x, int bits, int i) {
        if (bits == 0) {
            vertex.val = i + 1;
        }
        else {
            int v = (x >> (bits - 1)) & 1;
            if (vertex.children[v] == null) {
                vertex.children[v] = new Node();
            }
            addNumber(vertex.children[v], x, bits-1, i);
        }
    }

    public void addNumber(int x, int i) {
        addNumber(root, x, 32, i);
    }

    private int[] query(Node vertex, int x, int bits) {
        if (bits == 0) {
            int a[] = {0, vertex.val};
            return a;
        }
        else {
            int v = (x >> bits-1) & 1;
            int req = v == 0 ? 1 : 0;
            if (vertex.children[req] == null) {
                return query(vertex.children[v], x, bits-1);
            }
            else {
                int a[] = query(vertex.children[req], x, bits-1);
                int b[] = {((int) Math.pow(2, bits-1)) + a[0], a[1]};
                return b;
            }
        }
    }

    public int[] query(int x) {
        return query(root, x, 32);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Trie t1 = new Trie();
        Trie t2 = new Trie();
        int n = in.nextInt();
        int a[] = new int[n];
        int i;
        int rev[] = new int[n];
        for (i = 0; i < n; i++)
            a[i] = in.nextInt();
        int ans = 0, prev = 0;
        for (i = n-1; i >= 0; i--) {
            prev = prev ^ a[i];
            t1.addNumber(prev, i);
            int x[] = t1.query(prev);
            if (x[0] > ans) {
                ans = x[0];
                rev[i] = x[0];
            }
        }
        int ans2 = 0, max = 0;
        prev = 0;
        for (i = 0; i < n-1; i++) {
            prev = prev ^ a[i];
            t2.addNumber(prev, i);
            int x[] = t2.query(prev);
            if (x[0] > ans2) {
                ans2 = x[0];
            }
            if (ans2 + rev[i+1] > max) {
                max = ans2 + rev[i+1];
            }
        }
        System.out.println(max);
    }
}

