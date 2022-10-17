import java.util.*;
public class SpiralMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int rows = sc.nextInt();
        int cols = sc.nextInt();

        int [][] matrix = new int[rows][cols];

        for(int i =0;i<rows ; i++){
            for(int j=0; j<cols; j++){
                matrix[i][j] = sc.nextInt();
            }
        }

       int rowStart = 0;
       int rowEnd   = rows-1;
       int colStart = 0;
       int colEnd   = cols-1;
       
       while(rowStart<=rowEnd &&  colStart<=colEnd){
       //first row
       for(int i=colStart; i<= colEnd; i++){
        System.out.print(matrix[rowStart][i]+" ");
       }
       rowStart++;

       //last column
       for(int i = rowStart; i <= rowEnd; i++){
        System.out.print(matrix[i][colEnd]+" ");
       }
       colEnd--;

       //last row
       for(int i=colEnd; i>=colStart; i--){
        System.out.print(matrix[rowEnd][i]+" ");
       }
       rowEnd--;

       //first column
       for(int i=rowEnd; i>= rowStart; i--){
        System.out.print(matrix[i][colStart]+" ");
       }
       colStart++;
     }    

    }
}
