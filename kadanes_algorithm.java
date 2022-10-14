
import java.util.*;
public class kadanes_algorithm
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no. of elements in array");
        int n=sc.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the elements of the array : ");
        for(int i=0; i<n; i++)
        {
            a[i]=sc.nextInt();
        }
        int curr_sum=a[0];
        int total_sum=a[0];
        for(int i=1; i<a.length; i++)
        {
            if(curr_sum>=0)
                curr_sum+=a[i];
            else
                curr_sum=a[i];

            if(curr_sum>total_sum)
                total_sum=curr_sum;
        }
        System.out.println("Maximum sum subarray is : "+total_sum);
    }
}
