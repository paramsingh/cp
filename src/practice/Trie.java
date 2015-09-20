// Author: Param Singh <paramsingh258@gmail.com>
// A Lot Of Games: codeforces.com/problemset/problem/455/B

import java.util.Scanner;
public class Trie {
    private class Node {
        int win, lose;
        Node children[];
        Node() {
            children = new Node[26];
            for (int i = 0; i < 26; i++)
                children[i] = null;
            win  = -1;
            lose = -1;

        }
    }

    Node root;

    Trie() {
        root = new Node();
    }

    private void insert(Node vertex, String s) {
        if (s.equals("")) {
            vertex.win  = 1;
            vertex.lose = 0;
            return;
        }
        else {
            int next = s.charAt(0) - 'a';
            s = s.substring(1, s.length());
            if (vertex.children[next] == null) {
                vertex.children[next] = new Node();
            }
            if (s.length() % 2 == 0) {
                vertex.win = 1;
                if (vertex.lose == -1)
                    vertex.lose = 0;
            }
            else {
                vertex.lose = 1;
                if (vertex.win == -1)
                    vertex.win = 0;
            }
            insert(vertex.children[next], s);
        }
    }

    public void insert(String s) {
        insert(root, s);
    }

    public boolean canWin() {
        return root.win == 1;
    }

    public boolean canLose() {
        return root.lose == 1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        Trie t = new Trie();
        for (int i = 0; i < n; i++) {
            String s = in.next();
            t.insert(s);
        }

        if (t.canWin() && t.canLose()) {
            System.out.println("First");
        }
        else if (t.canWin()) {
            if (k % 2 == 0) {
                System.out.println("Second");
            }
            else {
                System.out.println("First");
            }
        }
        else if (t.canLose()) {
            System.out.println("Second");
        }
    }
}


