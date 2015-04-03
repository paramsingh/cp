import java.util.Scanner;
class PrimeFac
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner( System.in );
        int terms = in.nextInt();
        for(int q = 0; q<terms; q++)
        {
            int n = in.nextInt();
            System.out.println(sumOfDivisors(n));
        }
    }
    public static long sumOfDivisors(int n)
    {
        long prod=1;
        for(int k=2;k*k<=n;k++){
            int p=1;
            while(n%k==0){
                p=p*k+1;
                n/=k;
            }
            prod*=p;
        }
        if(n>1)
            prod*=1+n;
        return prod;
    }
}
