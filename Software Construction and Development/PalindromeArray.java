public class Palindrome{
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 2, 1};
        int[] arr2 = {1, 2, 3, 4, 5};

        boolean isPalindrome1 = isPalindrome(arr1);
        boolean isPalindrome2 = isPalindrome(arr2);
        
        System.out.println("Array 1:");
        for (int num : arr1) {
            System.out.print(num + " ");
        }
        System.out.println();
    

        System.out.println("Array 2:");
          for (int num : arr2) {
            System.out.print(num + " ");
        }
        System.out.println();

        System.out.println("Is array 1 a palindrome? " + isPalindrome1);
        System.out.println("Is array 2 a palindrome? " + isPalindrome2);
    }

    public static boolean isPalindrome(int[] array) {
        int left = 0;
        int right = array.length - 1;

        while (left < right) {
            if (array[left] != array[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}
