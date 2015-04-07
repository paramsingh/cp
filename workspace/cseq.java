import java.util.Scanner;
import java.math.BigInteger;
class CSEQ
{
    static long big = 1000003;
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int terms = in.nextInt();
        for(int q = 0; q<terms; q++){
            long n = in.nextLong();
            long l = in.nextLong();
            long r = in.nextLong();
            long diff = r - l + 1;
            int i,j;
            if(n==1){
                System.out.println(diff);
                continue;
            }
            long constdenfact = factmodbig(diff-1);
            long prevnumfact = ((constdenfact) * (diff % big)) % big;
            long prevdenfact = 1;
            long ans = 0;
            for(i=1;i<=n;i++){
                ans += ((prevnumfact % big) * invert_mod(prevdenfact)) % big;
                prevnumfact = ((prevnumfact % big) * ((diff+i)%big)) % big;
                prevdenfact = ((prevdenfact % big) * ((i+1) % big)) % big;
            }
            ans = ans % big;
            ans = ((ans % big) * invert_mod(constdenfact)) % big;
            System.out.println(ans);
        }
    }
    static long factmodbig(long n){
        long fact = 1;
        for(long i=2; i<=n; i++)
            fact = ((fact % big) * (i%big)) % big;
        return (fact % big);
    }
    static long invert_mod(long a) {
        long ex = big-2, result = 1;
        while (ex > 0) {
            if (ex % 2 == 1) {
                result = (result*a) % big;
            }
            a = (a*a) % big;
            ex /= 2;
        }
        return result;
    }
}
