
public class Array_2D {

	public static void main(String[] args) {
		
		int[][] x= new int [3][3];
		int[][] y = { {1,2,3}, {4,5,6}, {7,8,9}};
		for(int row=0; row<3;row++)
		{
			for(int col=0;col<3;col++)
			{
				System.out.print(x[row][col]+" ");
			}
			System.out.println();
		}
		
		System.out.println("\n");
		for(int row=0; row<3;row++)
		{
			for(int col=0;col<3;col++)
			{
				System.out.print(y[row][col]+" ");
			}
			System.out.println();
		}
		

	}

}
