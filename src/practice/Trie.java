// Author: Param Singh <paramsingh258@gmail.com>
// A Lot Of Games: codeforces.com/problemset/problem/455/B

import java.util.Scanner;
public class Trie {
    private class Node {
        int want;
        int num;
        int win, lose;
        Node children[];
        Node() {
            children = new Node[26];
            for (int i = 0; i < 26; i++)
                children[i] = null;
            num = 0;
            want = -1;
            win = -1;
            lose = -1;
        }
    }

    Node root;

    Trie() {
        root = new Node();
    }

    private void insert(Node vertex, String s) {
        if (s.equals("")) {
            return;
        }
        else {
            int c = s.charAt(0) - 'a';
            s = s.substring(1, s.length());
            if (vertex.children[c] == null) {
                vertex.num++;
                vertex.children[c] = new Node();
            }
            insert(vertex.children[c], s);
        }

    }

    private void fill(Node vertex) {
        if (vertex.num == 0) {
            vertex.win = 0;
            vertex.lose = 1;
            return;
        }
        else {
            int onlywin = 0, onlylose = 0, never = 0, always = 0;

            for (Node x: vertex.children) {
                if (x != null) {
                    fill(x);
                    if (x.win == 0 && x.lose == 0)
                        never++;
                    if (x.win == 0 && x.lose == 1)
                        onlylose++;
                    if (x.win == 1 && x.lose == 0)
                        onlywin++;
                    if (x.win == 1 && x.lose == 1)
                        always++;
                }
            }

            if (always == vertex.num) {
                vertex.win = 0;
                vertex.lose = 0;
            }
            else if (never > 0) {
                vertex.win = 1;
                vertex.lose = 1;
            }
            else {
                if (always + onlywin == vertex.num) {
                    vertex.lose = 1;
                    vertex.win = 0;
                }
                else if (always + onlylose == vertex.num) {
                    vertex.win = 1;
                    vertex.lose = 0;
                }
                else if (always + onlywin + onlylose == vertex.num) {
                    vertex.win = 1;
                    vertex.lose = 1;
                }


            }
        }
    }

    public int[] result() {
        // if the starter can only win, returns 1
        // if the starter can only lose, returns 2
        // if the starter always gets what she wants, returns 3
        // if the starter never gets what she wants, returns 4
        fill(root);
        int a[] = {root.win, root.lose};
        return a;
    }

    public void insert(String s) {
        insert(root, s);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        Trie t = new Trie();
        for (int i = 0; i < n; i++) {
            t.insert(in.next());
        }
        int a[]= t.result();
        int win = a[0], lose = a[1];
        if (win == 0 && lose == 0) {
            System.out.println("Second");
        }
        else if (win == 1 && lose == 1) {
            System.out.println("First");
        }
        else if (win == 1 && lose == 0) {
            if (k % 2 == 0)
                System.out.println("Second");
            else
                System.out.println("First");
        }
        else if (win == 0 && lose == 1) {
            System.out.println("Second");
        }
    }
}


