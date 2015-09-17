// Author: Param Singh <paramsingh258@gmail.com>
// http://www.spoj.com/problems/PHONELST/

import java.io.*;
class Trie {
    private class Node {
        Node children[];
        boolean flag;
        Node() {
            children = new Node[10];
            for (int i = 0; i < 10; i++)
                children[i] = null;
            flag = false;
        }
    }

    private Node root;

    Trie() {
        root = new Node();
    }

    private void insert(Node vertex, String s) {
        if (s.equals("")) {
            vertex.flag = true;
            return;
        }
        else {
            int next = s.charAt(0) - '0';
            if (vertex.children[next] == null) {
                vertex.children[next] = new Node();
            }
            insert(vertex.children[next], s.substring(1, s.length()));
        }
    }

    public void insert(String s) {
        insert(root, s);
    }

    private boolean query(Node vertex, String s) {
        if (s.equals("")) {
            return false;
        }
        if (vertex.flag) {
            return true;
        }
        else {
            int c = s.charAt(0) - '0';
            return query(vertex.children[c], s.substring(1, s.length()));
        }
    }

    public boolean query(String s) {
        return query(root, s);
    }
}


class PhoneLST {
        public static void main(String[] args) throws IOException {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int t = Integer.parseInt(in.readLine());
        for (int term = 0; term < t; term++) {
            int n = Integer.parseInt(in.readLine());
            String a[] = new String[n];
            Trie tr = new Trie();
            int i;
            for (i = 0; i < n; i++) {
                a[i] = in.readLine();
                tr.insert(a[i]);
            }
            boolean flag = false;
            for (i = 0; i < n; i++) {
                if (tr.query(a[i])) {
                    flag = true;
                    break;
                }
            }
            if (flag)
                System.out.println("NO");
            else
                System.out.println("YES");
        }
    }
}


