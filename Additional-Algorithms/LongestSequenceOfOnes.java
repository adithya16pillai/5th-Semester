public class LongestSequenceOfOnes {
    public static int longestSequenceOfOnes(int binaryNumber) {
        String binaryString = Integer.toBinaryString(binaryNumber);
        int count = 0;
        int maxCount = 0;
        for (char digit : binaryString.toCharArray()) {
            if (digit == '1') {
                count++;
                if (count > maxCount) {
                    maxCount = count;
                }
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
    public static void main(String[] args) {
        int binaryNumber = 0b1101110111111001; // Binary representation of 87769
        int longestSequence = longestSequenceOfOnes(binaryNumber);
        System.out.println("The longest sequence of 1's in " + Integer.toBinaryString(binaryNumber) + " is: " + longestSequence);
    }
}

// public class Longafterflip {
//     public static int longestConsecutiveOnes(int n) {
//         String binary = Integer.toBinaryString(n);
//         int maxLength = 0;
//         int currentLength = 0;
//         int previousLength = 0;
//         for (char bit : binary.toCharArray()) {
//             if (bit == '1') {
//                 currentLength++;
//             } else {
//                 maxLength = Math.max(maxLength, currentLength + previousLength + 1);
//                 previousLength = currentLength;
//                 currentLength = 0;
//             }
//         }
//         maxLength = Math.max(maxLength, currentLength + previousLength + 1);
//         return maxLength;
//     }
//     public static void main(String[] args) {
//         int n = 0b111011110;
//         System.out.println(longestConsecutiveOnes(n)); // Output: 8
//     }
// }