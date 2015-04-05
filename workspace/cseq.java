import java.util.Scanner;
import java.math.BigInteger;
class CSEQ
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int terms = in.nextInt();
        for(int q = 0; q<terms; q++){
            int n = in.nextInt();
            int l = in.nextInt();
            int r = in.nextInt();
            int diff = r - l + 1;
            int i,j;
            if(n==1){
                System.out.println(diff);
                continue;
            }
            BigInteger list[][] = new BigInteger[n-1][diff];
            BigInteger sum = new BigInteger(diff+"");
            for(i=1; i<=diff; i++){
                list[0][i-1] = new BigInteger(i+"");
                sum = sum.add(list[0][i-1]);
            }
            for(i=1;i<n-1;i++){
                list[i][0] = new BigInteger("1");
            }
            for(i=1;i<n-1;i++){
                for(j=1; j<diff; j++){
                    list[i][j] = list[i][j-1].add(list[i-1][j]);
                    sum = sum.add(list[i][j]);
                }
            }
            /* for(i=0;i<n-1;i++){
                for(j=0;j<diff;j++){
                    System.out.print(list[i][j]);
                    System.out.print("\t");
                }
                System.out.println();
            } */
            System.out.println(sum.mod(new BigInteger("1000003")));
        }
    }
}
