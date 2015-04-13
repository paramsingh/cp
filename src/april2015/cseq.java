import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
class CSEQ
{
    // ans = d+n c n - 1
    static int big = 1000003;
    public static void main(String[] args)
    {
        long facts[] = new long[1000003];
        facts[0] = 1;
        for(int k=1; k<1000003; k++)
            facts[k] = ((facts[k-1] % big) * k) % big;
        Scanner in = new Scanner(System.in);
        int terms = in.nextInt();
        for(int q = 0; q<terms; q++){
            int n = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();
            int d = r - l + 1;
            int i,j;
            if(n==1){
                System.out.println(d);
                continue;
            }
            // ans = (d+n c n) - 1
            // now have to use lucas' theorem
            int num = d + n;
            int den = n;
            long ans = 1;
            while(num!=0 || den!=0){
                int ni = num % big;
                int di = den % big;
                //System.out.println(ni+", "+di);
                if(di>ni){
                    ans = 0;
                    break;
                }
                ans = ((ans % big) * ((facts[ni] * invertMod(facts[di]) * invertMod(facts[ni-di])) % big)) % big;
                num /= big;
                den /= big;
            }

            ans = ((ans % big) + (((-1 % big) + big) % big)) % big;
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
