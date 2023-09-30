//Max Equilibrium Sum
public class MES {
    public static int getMaxEquilibriumSumOptimized(int[] arr) {
        int totalSum = 0;
        int leftSum = 0;
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            totalSum += arr[i];
        }
        for (int i = 0; i < arr.length; i++) {
            totalSum -= arr[i];
            if (leftSum == totalSum && leftSum > maxSum) {
                maxSum = leftSum;
            }
            leftSum += arr[i];
        }
    return maxSum;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};
        int maxSum = getMaxEquilibriumSumOptimized(arr);
        System.out.println("Max Equilibrium Sum : " + maxSum);
    }
}