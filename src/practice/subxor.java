// Author: Param Singh <paramsingh258@gmail.com>
// http://www.spoj.com/problems/SUBXOR/
import java.io.*;
class Trie {
    private class Node {
        int val;
        Node children[];
        Node() {
            val = 0;
            children = new Node[2];
            children[0] = null;
            children[1] = null;
        }
    }

    private Node root;

    Trie() {
        root = new Node();
    }

    private void insert(Node vertex, int n, int bits) {
        if (bits == 0) {
            vertex.val++;
            return;
        }
        else {
            int bit = (n >> (bits-1)) & 1;
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
        if (bits == 0) {
            if (k <= 0)
                return 0;
            else
                return vertex.val;
        }
        else {
            int v = (n >> (bits - 1)) & 1;
            int r = (v == 0) ? 1 : 0;
            int a = 0, b = 0;
            if (vertex.children[v] != null)
                a = query(vertex.children[v], n, k, bits-1);
            if (vertex.children[r] != null)
                b = query(vertex.children[r], n, k - (int) Math.pow(2, bits-1), bits-1);
            return a + b;
        }
    }

    public int query(int n, int k) {
        return query(root, n, k, 32);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        for (int a = 0; a < t; a++) {
            Trie trie = new Trie();
            String s[] = in.readLine().split(" ");
            int size = Integer.parseInt(s[0]), k = Integer.parseInt(s[1]);
            String s1[] = in.readLine().split(" ");
            int ans = 0, p = 0, q;
            for (int i = 0; i < size; i++) {
                int n = Integer.parseInt(s1[i]);
                q = p ^ n;
                ans += trie.query(q, k);
                trie.insert(q);
                p = q;
            System.out.println(ans);
            }
        }
    }
}
