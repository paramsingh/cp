import java.util.Scanner;

class Node {
    int val, index;
    int li, ri;
    public Node(int a, int b, int c, int d){
        this.val = a;
        this.index = b;
        this.li = c;
        this.ri = d;
    }
}

class SegmentTree {
    Node node;
    SegmentTree left, right;

    public static SegmentTree create(int values[], int l, int r){
        SegmentTree cur = new SegmentTree();
        if(l==r){
            cur.node = new Node(values[l], l, l, l);
            return cur;
        }
        else {
            cur.left = create(values, l, (l+r)/2);
            cur.right = create(values, (l+r)/2 + 1, r);
        }
        if (cur.left.node.val > cur.right.node.val)
            cur.node = new Node(cur.left.node.val, cur.left.node.index, l, r);
        else
            cur.node = new Node(cur.right.node.val, cur.right.node.index, l, r);
        return cur;
    }

    int query(int l, int r){
        return helper(this, l, r);
    }

    static int helper(SegmentTree tree, int l, int r){
        int lv, rv;
        int x = tree.node.li;
        int y = tree.node.ri;
        if (r < x || y < l)
            return Integer.MIN_VALUE;
        if(l <= x  && l<=y && x<=r && y <= r){
            return tree.node.val;
        }
        else {
            lv = helper(tree.left,  l, r);
            rv = helper(tree.right, l, r);
        }
        return (lv > rv) ? lv : rv;
    }
}

class FRMQ {
    public static void main(String[] args) {
        Scanner in = new Scanner( System.in );
        int n = in.nextInt();
        int arr[] = new int[n];
        int i;
        for(i = 0; i<n; i++)
            arr[i] = in.nextInt();
        SegmentTree tree = SegmentTree.create(arr, 0, n-1);
        int m = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        for(i=0;i<m;i++){
            int max, min;
            max = x > y ? x : y;
            min = x > y ? y : x;
            System.out.println("Range: "+ min+", "+max);
            System.out.println(tree.query(min, max));
            x = (x+7) % (n-1);
            y = (y+11) % n;
        }
    }
}
