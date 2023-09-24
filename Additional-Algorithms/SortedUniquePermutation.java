import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class SortedUniquePermutation {
    public static void main(String[] args) {
        String input="ABC";
        distinctPermutations(input);
    }
    public static void distinctPermutations(String input) {
        char[] chars = input.toCharArray();
        Arrays.sort(chars);
        input = new String(chars);
        permute(input.toCharArray(),0);
    }
    public static void permute(char[] chars, int index) {
        if( index == chars.length-1) {
            System.out.println(String.valueOf(chars));
            return;
        }
        Set<Character> used = new HashSet<>();
            for(int i = index; i < chars.length; i++) {
                if(used.contains(chars[i])) {
                    continue;
                }
                used.add(chars[i]);
                swap(chars, index, i);
                permute(chars, index+1);
                swap(chars, index, i);
            }
    }
    public static void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}