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
            long constDenFact = factModBig(diff-1);
            long prevNumFact = ((constDenFact) * (diff % big)) % big;
            long prevDenFact = 1;
            long ans = 0;
            long inverse = invertMod(prevDenFact);
            for(i=1;i<=n;i++){
                ans += ((prevNumFact % big) * inverse) % big;
                prevNumFact = ((prevNumFact % big) * ((diff+i) % big)) % big;
                inverse = (inverse * (invertMod(i+1) % big)) % big;
            }
            ans = ans % big;
            ans = ((ans % big) * invertMod(constDenFact)) % big;
            System.out.println(ans);
        }
    }


    static long factModBig(long n){
        long fact = 1;
        for(long i=2; i<=n; i++)
            fact = ((fact % big) * (i%big)) % big;
        return (fact % big);
    }


    static long invertMod(long a) {
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
