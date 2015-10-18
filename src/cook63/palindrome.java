import java.io.*;
class Trie {
    private class Node {
        int mark;
        Node children[];
        int num;
        Node() {
            num = 0;
            mark = 0;
            children = new Node[26];
            int i;
            for (i = 0; i < 26; i++) {
                children[i] = null;
            }
        }
    }

    Node root;
    Trie() {
        root = new Node();
    }

    private void add(Node x, String s) {
        if (s.equals("")) {
            x.mark ++;
            return;
        }
        else {
            int c = s.charAt(0) - 'a';
            s = s.substring(1, s.length());
            if (x.children[c] == null) {
                x.children[c] = new Node();
                x.num++;
            }
            add(x.children[c], s);
        }
    }

    public void add(String s) {
        add(root, s);
    }

    public int lookup(Node x, String s) {
        if (s.equals("")) {
            int t = 0;
            if (x.num != 0 && x.mark != 0) {
                t += x.mark;
            }
            return numPal(x, "") + t;
        }
        else {
            int c = s.charAt(0) - 'a';
            int ans = 0;
            if (x.mark != 0) {
                if (s.equals(new StringBuilder(s).reverse().toString()))
                    ans += x.mark;
            }
            if (x.children[c] != null) {
                ans += lookup(x.children[c], s.substring(1, s.length()));
            }
            return ans;
        }
    }

    public int lookup(String s) {
        return lookup(root, s);
    }

    public int numPal(Node x, String s) {
        if (x.num == 0) {
            String rev = new StringBuilder(s).reverse().toString();
            if (s.equals(rev))
                return 1;
            else
                return 0;
        }
        else {
            int i;
            int ans = 0;
            for (i = 0; i < 26; i++) {
                char c = (char) ('a' + i);
                if (x.children[i] != null)
                    ans += numPal(x.children[i], s+Character.toString(c));
            }
            return ans;
        }
    }

    public static void main(String[] args) throws Exception {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int t = Integer.parseInt(in.readLine());
        for (int loop = 0; loop < t; loop++) {
            int n = Integer.parseInt(in.readLine());
            Trie tr = new Trie();
            Trie revt = new Trie();
            int ans = 0;
            int i;
            String s = in.readLine();
            String rev = new StringBuilder(s).reverse().toString();
            tr.add(s);
            revt.add(rev);
            for (i = 1; i < n; i++) {
                s = in.readLine();
                rev = new StringBuilder(s).reverse().toString();
                ans += revt.lookup(s) + tr.lookup(rev);
                tr.add(s);
                revt.add(rev);
            }
            System.out.println(ans);
        }
    }
}

