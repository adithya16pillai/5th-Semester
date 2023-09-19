import java.io.*;
public class CFG {
    static void leftRotate (int arr[], int d, int n) {
        int i, j;
        if (d == 0 || d == n)
            return;
        /* If number of elements to be rotated is more than array size */
        if (d > n)
            d = d % n;
    i = d;
    j = n - d;
    while(i != j) {
        if(i < j) {
            swap(arr, d-i, d + j-i, i);
            j -= i;
        } else {
            swap(arr, d-i, d, j);
            i -= j;
        }
        // printArray (arr, 7);
    }
    /*Finally, block swap A and B*/
    swap(arr, d-i, d,i);
    }
    public static void printArray(int arr[], int size) {
        int i;
        for (i = 0;i < size;i++)
            System.out.print(arr[i] + " ");
            System.out.println();
    }
    public static void swap(int arr[], int fi, int si,int d) {
        int i, temp;
        for (i = 0;i < d;i++) {
            temp = arr[fi +i];
            arr[fi +i] = arr[si +i];
            arr[si +i] = temp;
        }
    }

    public static void main(String[] args)  {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
        leftRotate(arr, 2, 7);
        printArray(arr, 7);
    }
}