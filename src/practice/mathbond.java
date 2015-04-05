import java.io.*;
class MathBond {
    public static void main(String[] args) throws Exception {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int terms = Integer.parseInt(in.readLine());
        for(int q=0; q<terms; q++){
            long n = Long.parseLong(in.readLine());
            if(n==1){
                System.out.println("1");
                continue;
            }
            long dup = n;
            long big = 1000000007;
            long acc = n;
            long i;
            long half = n / 2;
            for(i= 2; i<=half; i++){
                acc += (i * (n/i));
            }
            acc += ((n-half) * (n+half+1) / 2);
            System.out.println(acc % big);
        }
    }
}
