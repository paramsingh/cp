import java.util.Scanner;
class Vats {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner( System.in );
        int terms = in.nextInt();
        for(int q=1; q<=terms; q++){
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            if( c%a == 0 || c%b == 0){
                System.out.println("Case "+q+": "+ "Yes");
                continue;
            }
            else {
                // test code please ignore
            }
        }
    }
}
