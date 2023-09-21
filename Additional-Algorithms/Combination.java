import java.util.List;
import java.util.*;

public class Combination {
    static int fact(int number) {
        int f = 1;
        int j = 1;
        while(j <= number) {
            f=f*j;
            j++;
        }
        return f;
    }
    public static void main(String args[]) {
        List<Integer> numbers = new ArrayList<Integer>();
        numbers.add(9);
        numbers.add(10);
        numbers.add(11);
        numbers.add(12);
        numbers.add(13);
        int n = numbers.size();
        int r = 2;
        int result;
        result = fact(n) / (fact(r) * fact(n-r));
        System.out.println("The combination value for the members list is: " + result);
    }
}
