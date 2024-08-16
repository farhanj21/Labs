import java.util.Random;

public class DiceGame {
    public static void main(String[] args) 
    {
        int[][] board = new int[10][10];

        int x = 0, y = 0;

        Random rnd = new Random();

        int itr = 0; 
        while (x < 9 || y < 9) {
            itr++;

            System.out.println("Iteration " + itr + ":");
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i == x && j == y) {
                        System.out.print("x ");
                    } else {
                        System.out.print(board[i][j] + " ");
                    }
                }
                System.out.println();
            }

            int roll = rnd.nextInt(6) + 1;
            System.out.println("Number generated: " + roll);

            if (x % 2 == 0) { 
                y += roll;
                if (y >= 10) {
                    x += 1;
                    y = 9;
                }
            } else {  
                y -= roll;
                if (y < 0) {
                    x += 1;
                    y = 0;
                }
            }

            x = Math.min(9, x);
            y = Math.min(9, y);
        }
        System.out.println("Final state with the pointer at the end:");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 9 && j == 9) {
                    System.out.print("x ");
                } else {
                    System.out.print(board[i][j] + " ");
                }
            }
            System.out.println();
        }
        
        System.out.println("Number of iterations: " + itr);
    }
}
