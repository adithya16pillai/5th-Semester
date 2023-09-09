import java.util.*;
public class BinaryPalindromeChecker {
    public static boolean isBinaryPalindrome(int x) {
        int reversed = 0;
        int original = x;
        while (x > 0) {
            reversed <<= 1; // Left shift by 1 bit
            reversed |= (x & 1); // Add the least significant bit of 'x' to'reversed'
            x >>= 1; // Right shift by 1 bit
        }
        return reversed == original;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        if (isBinaryPalindrome(x)) {
            System.out.println(x + " has a binary palindrome representation.");
        } else {
            System.out.println(x + " does not have a binary palindrome representation.");
        }
    }
}