import java.io.*;
class Solve2 {
    public static void main(String[] args) throws Exception{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader in = new BufferedReader(isr);
        int terms = Integer.parseInt(in.readLine());
        int term;
        double token1, token2, token3;
        token1 = token2 = token3 = 0;
        String operators = "+-*/";
        for(term = 0; term<terms; term++){
            String equation = in.readLine().replaceAll(" ", "");
            String tokens[] = new String[3];
            String temp[] = equation.split("=");
            tokens[2] = temp[1];
            int no = 0;
            char val_op[] = new char[3];
            int index_op[] = new int[3];
            int len = temp[0].length();
            for(int i=0;i<len;i++){
                char ch = temp[0].charAt(i);
                if(operators.indexOf(ch) != -1){
                    val_op[no] = ch;
                    index_op[no] = i;
                    no++;
                }
            }
            char token_op = '\n';
            if(no == 1){
                token_op = val_op[0];
                tokens[0] = temp[0].substring(0, index_op[0]);
                tokens[1] = temp[0].substring(index_op[0]+1);
            }
            else if(no == 2){
                if( val_op[0] == '-' ){
                    token_op = val_op[1];
                    tokens[0] = temp[0].substring(0, index_op[1]);
                    tokens[1] = temp[0].substring(index_op[1]+1);
                }
                else{
                    token_op = val_op[0];
                    tokens[0] = temp[0].substring(0, index_op[0]);
                    tokens[1] = temp[0].substring(index_op[0]+1);
                }
            }
            else{
                token_op = val_op[1];
                tokens[0] = temp[0].substring(0, index_op[1]);
                tokens[1] = temp[0].substring(index_op[1]+1);
            }
            int x = -1;
            boolean minus_x = false;
            for(int i=0;i<3;i++){
                if(tokens[i].indexOf('x') != -1){
                    if(tokens[i].indexOf('-') != -1){
                        minus_x = true;
                    }
                    x = i+1;
                }
            }
            //System.out.println(token_op);
            if(x==1){
                double answer=0;
                token2 = Double.parseDouble(tokens[1]);
                token3 = Double.parseDouble(tokens[2]);
                switch(token_op){
                    case '+':
                        answer = token3 - token2;
                        break;
                    case '-':
                        answer = token3 + token2;
                        break;
                    case '*':
                        answer = token3 / token2;
                        break;
                    case '/':
                        answer = token3 * token2;
                        break;
                    default:
                        break;
                }
                if(minus_x)
                    answer = -1*answer;
                System.out.printf("%.6f\n",answer);
            }
            else if(x == 2){
                double answer = 0;
                token1 = Double.parseDouble(tokens[0]);
                token3 = Double.parseDouble(tokens[2]);
                switch(token_op){
                    case '+':
                        answer = token3 - token1;
                        break;
                    case '-':
                        answer = token1 - token3;
                        break;
                    case '*':
                        answer = token3 / token1;
                        break;
                    case '/':
                        answer = token1 / token3;
                        break;
                    default:
                        break;
                }
                if(minus_x)
                    answer = -1*answer;
                System.out.printf("%.6f\n", answer);
            }
            else{
                double answer = 0;
                token1 = Double.parseDouble(tokens[0]);
                token2 = Double.parseDouble(tokens[1]);
                switch(token_op){
                    case '+':
                        answer = token1 + token2;
                        break;
                    case '-':
                        answer = token1 - token2;
                        break;
                    case '*':
                        answer = token1 * token2;
                        break;
                    case '/':
                        answer = token1 / token2;
                        break;
                    default:
                        break;
                }
                if(minus_x)
                    answer = -1*answer;
                System.out.printf("%.6f\n", answer);
            }
        }
    }
}
