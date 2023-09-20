public class LeadersInArray { //Brute Force Algorithm 
    public static void main(String[] args) {
        int[] array = {16,17,4,3,5,2};
        findLeaders(array);
    }
    public static void findLeaders(int[] array) {
        int length = array.length;
        for(int i = 0; i < length; i++) { 
            boolean isLeader = true;
            for(int j = i + 1; j < length; j++) {
                if (array[i] <= array[j]) {
                    isLeader = false;
                    break;
                }
            }
            if(isLeader) {
                System.out.print(array[i] + " ");
            }
        }
    }
}
