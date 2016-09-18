// Author: Param Singh <paramsingh258@gmail.com>

import java.util.Scanner;
class GravityGuy {

    Lane lane1, lane2;

    private class Lane {
        String lane;
        int length;
        boolean solvableFromHere;

        Lane(String s) {
            lane = s;
            length = s.length();
            solvableFromHere = true;
        }

        public char charAt(int i) {
            return lane.charAt(i);
        }
    }

    public GravityGuy(String s1, String s2) {
        lane1 = new Lane(s1);
        lane2 = new Lane(s2);
    }

    public void solve() {
        int x = solveWith(lane1, lane2);
        if (x == -1) {
            System.out.println("No");
            return;
        }
        int y = solveWith(lane2, lane1);
        System.out.println("Yes");
        System.out.println((x < y) ? x : y);
    }

    public int solveWith(Lane cur, Lane other) {
        int j, count = 0;
        for (j = -1; j < cur.length - 1; j++) {
            if (cur.charAt(j+1) == '#') {
                if (other.charAt(j+1) == '#')
                    return -1;
                else {
                    count++;
                    Lane temp = cur;
                    cur = other;
                    other = temp;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a = 0; a < t; a++) {
            String lane1 = in.next();
            String lane2 = in.next();
            GravityGuy solver = new GravityGuy(lane1, lane2);
            solver.solve();
        }
    }
}
