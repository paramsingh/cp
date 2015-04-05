import java.util.Scanner;
class Digvijay {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner( System.in );
        int terms = in.nextInt();
        for(int q=0; q<terms; q++){
            int base = in.nextInt();
            int mod = in.nextInt();
            String s = in.next();
            int l = s.length();
            int num = 0;
            int i;
            for(i=0;i<l;i++){
                int digit = s.charAt(i) - '0';
                num = num * base + digit;
                System.out.print(num%mod + " ");
            }
            System.out.println();
        }
    }
}
