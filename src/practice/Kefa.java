// Author: Param Singh <paramsingh258@gmail.com>
// Kefa and Park: http://codeforces.com/contest/580/problem/C

import java.io.*;
import java.util.*;
public class Kefa {
    static class Node {
        List<Node> children;
        int id;
        int num;
        boolean cat;
        int left, right;
        Node() {
            left = right = 0;
            children = new ArrayList<Node>();
            num = 0;
            cat = false;
        }

        void add_child(Node x) {
            num++;
            children.add(x);
        }

        void add_cat() {
            cat = true;
        }
    }

    public static int num_leafs(Node vertex, Node prev, int consecutive, int m) {
        int ans = 0;
        if (vertex.num == 1 && prev != null) {
            if (vertex.cat)
                consecutive++;
            if (m >= consecutive)
                ans = 1;
            else
                ans = 0;
        }
        else {
            if (vertex.cat) {
                if (m == consecutive)
                    ans = 0;
                else {
                    for (Node x: vertex.children) {
                        if (prev != null && prev.id == x.id)
                            continue;
                        ans += num_leafs(x, vertex, consecutive+1, m);
                    }
                }
            }
            else {
                for (Node x: vertex.children) {
                    if (prev != null && prev.id == x.id)
                        continue;
                    ans += num_leafs(x, vertex, 0, m);
                }
                return ans;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s[] = in.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);

        s = in.readLine().split(" ");
        Node tree[] = new Node[n];

        for (int i = 0; i < n; i++) {
            tree[i] = new Node();
            tree[i].id = i;
            if (s[i].equals("1"))
                tree[i].add_cat();
        }

        if (n == 1) {
            if (tree[0].cat && m != 0)
                System.out.println(0);
            else
                System.out.println(1);
            System.exit(0);
        }

        int a, b;
        for (int i = 1; i < n; i++) {
            s = in.readLine().split(" ");
            a = Integer.parseInt(s[0]);
            b = Integer.parseInt(s[1]);
            tree[a-1].add_child(tree[b-1]);
            tree[b-1].add_child(tree[a-1]);
        }
        System.out.println(num_leafs(tree[0], null, 0, m));
    }
}

