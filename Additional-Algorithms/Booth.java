import java.util.Scanner;
public class Booth {
    public int multiply(int n1, int n2) {
        int m = n1;
        int r = n2;
        int A = n1;  
        int S = -n1;
        int P = 0; 
        int count = Integer.SIZE;
        System.out.print(count);
        while (count > 0) {
            if ((r & 1) == 1) {
                P += A;
                S += m;
            }
            A <<= 1;
            S <<= 1;
            count--;
            r >>= 1;
        }
        return P;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Booth b = new Booth();
        System.out.println("Enter two integer numbers -");
        int n1 = scan.nextInt();
        int n2 = scan.nextInt();
        int result = b.multiply(n1, n2);
        System.out.println("\n\nResult : " + n1 + " * " + n2 + " = " + result);
    }
}
