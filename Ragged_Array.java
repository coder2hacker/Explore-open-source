import java.util.*;
public class Ragged_Array {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the Number of Rows in the Ragged array: ");
		int row =sc.nextInt();
		//Asking for the number of rows
		int [][] arr=new int [row][]; //u have to mention row number
		/*
		 In case of Ragged Array or Zagged Array the number of elements that means 
		 the number of columns are different for each row.
		 So, for this scenario at the time of Ragged Array declaration at first,
		 we have to define the number of total rows without defining the column 
		 number.
		 Row number mentioning is mandatory.
		 */
		for(int i=0;i<row;i++)
		{
			System.out.print("Enter the number of Elements in row: "+(i+1)+": ");
			arr[i]=new int[sc.nextInt()];
		}
		/*
		 Here, we have defined the number of elements for each row.
		 */
//		arr[0]= new int [4];
//		arr[1]=new int[5];
//		arr[2]=new int [2];
		for (int i=0;i<arr.length;i++)
		{
			for(int j=0; j<arr[i].length;j++)
			{
				System.out.print("Enter the elements in row:"+(i+1)+": ");
				arr[i][j]=sc.nextInt();
			}
			System.out.println();
		}
		/*
		 Here, we have initialized the Ragged Array after taking values from the user.
		 */
		for (int i=0;i<arr.length;i++)
		{
			for(int j=0; j<arr[i].length;j++)
			{
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		//This block has been used to print all the elements of the Ragged Array.
		sc.close();
	}

}