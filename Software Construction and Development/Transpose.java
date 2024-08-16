public class transpose 
{
    public static void main(String[] args) {
        int[][] orignal = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        int rows = orignal.length;
        int cols = orignal[0].length;

        int[][] transposedMatrix = new int[cols][rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposedMatrix[j][i] = orignal[i][j];
            }
        }

        System.out.println("Original Matrix:");
        print(orignal);

        System.out.println("Transposed Matrix:");
        print(transposedMatrix);
    }

    public static void print(int[][] matrix) {
        for (int[] row : matrix) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
