// Author: Param Singh <paramsingh258@gmail.com>
// http://www.spoj.com/problems/SUBXOR/
import java.io.*;
class Trie {
    private class Node {
        int val;
        int num[];
        Node children[];
        Node() {
            val = 0;
            children = new Node[2];
            num = new int[2];
            num[0] = 0;
            num[1] = 0;
            children[0] = null;
            children[1] = null;
        }
    }

    private Node root;

    Trie() {
        root = new Node();
        insert(0);
    }

    private void insert(Node vertex, int n, int bits) {
        if (bits == 0) {
            return;
        }
        else {
            int bit = (n >> (bits-1)) & 1;
            vertex.num[bit]++;
            if (vertex.children[bit] == null) {
                vertex.children[bit] = new Node();
            }
            insert(vertex.children[bit], n, bits-1);
        }
    }

    public void insert(int n) {
        insert(root, n, 32);
    }

    private int query(Node vertex, int n, int k, int bits) {
        if (bits == -1 || vertex == null)
            return 0;
        int p = (n >> bits) & 1;
        int q = (k >> bits) & 1;
        if (q == 1) {
            if (p == 0)
                return vertex.num[0] + query(vertex.children[1], n, k, bits-1);
            else
                return vertex.num[1] + query(vertex.children[0], n, k, bits-1);
        }
        else {
            if (p == 0)
                return query(vertex.children[0], n, k, bits - 1);
            else
                return query(vertex.children[1], n, k, bits - 1);
        }
    }

    public int query(int n, int k) {
        return query(root, n, k, 31);
    }

    public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int t = Integer.parseInt(in.readLine());
        for (int a = 0; a < t; a++) {
            Trie trie = new Trie();
            String s[] = in.readLine().split(" ");
            int size = Integer.parseInt(s[0]), k = Integer.parseInt(s[1]);
            String s1[] = in.readLine().split(" ");
            int p = 0, q;
            long ans = 0;
            for (int i = 0; i < size; i++) {
                int n = Integer.parseInt(s1[i]);
                q = p ^ n;
                ans += trie.query(q, k);
                trie.insert(q);
                p = q;
            }
            System.out.println(ans);
        }
    }
}
