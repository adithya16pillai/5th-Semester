public class SegmentedSieve {
    static void SegSieve(int l,int h) {
    //step1
        boolean prime[] = new boolean[h + 1];
    //step 2
    for (int p = 2; p * p <= h; p++) {
        int sm=(l/p)*p;
        if (sm <l) {
            sm=sm+p;
        }
        for (int i = sm; i <= h; i += p)
            prime[i] = true;
        }
    //step 3 Print all prime numbers
        for (int i = l; i <= h; i++) {
            if (prime[i] == false)
                System.out.print(i + " ");
        }
    }
    public static void main(String[] args) {
        SegSieve(10, 30);
    }
}
