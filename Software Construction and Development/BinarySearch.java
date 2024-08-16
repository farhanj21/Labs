import java.util.Comparator;

public class BinarySearch<T> {
    public static <T extends Comparable<T>> int binarySearch(T[] sortArr, T goal)
    {
        int left = 0;
        int right = sortArr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int compare = goal.compareTo(sortArr[mid]);

            if (compare == 0) {
                return mid; 
            } else if (compare < 0) {
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }

        return -1; 
    }

    public static void main(String[] args) {
        Integer[] intArr = {1, 2, 3, 4, 5, 6};
        int intIndex = binarySearch(intArr, 4);
        System.out.println("Index of 4 in Integer Array: " + intIndex);


        String[] strArr = {"A", "B", "C", "D", "E", "F"};
        int stringIndex = binarySearch(strArr, "E");
        System.out.println("Index of 'E' in String Array: " + stringIndex);

        Double[] doubleArr = {1.1, 2.1, 3.1, 4.1, 5.1, 6.1};
        int doubleIndex = binarySearch(doubleArr, 4.1);
        System.out.println("Index of 4.1 in Double Array: " + doubleIndex);
    }
}
