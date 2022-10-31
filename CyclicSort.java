import java.util.*;
public class CycleSort{  
        public static int[] rotate(int position,int element,int array[],int strt){
            while (position != strt) 
       { 
      position = strt; 
                        for (int i = strt+1; i<array.length; i++) 
                            if (array[i] < element)
                                position += 1; 
                        while(element == array[position])
                            position += 1; 
                        if(element != array[position]) 
                            { 
        int temp = element; 
        element = array[position]; 
        array[position] = temp;         
                            } 
      } 
            return array;
        }
      
    public static void main(String args[]){  
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of elements you want to add : ");
        int n=in.nextInt();
        System.out.println("Enter all the elements : ");
        int a[]=new int[n];
        for(int i=0;i<n;i++){
            a[i]=in.nextInt();
        } 
       
        System.out.print("Before Sorting : "); 
            for (int i =0; i<n; i++) 
    System.out.print(a[i] + " "); 
  
        System.out.println();
        int writes = 0; 
        for (int strt=0; strt<=n-2; strt++) 
  { 
            int element = a[strt]; 
            int position = strt; 
      for (int i = strt+1; i<n; i++) 
    if (a[i] < element)
                    position++; 
   
            if (position == strt) 
    continue;   
            while (element == a[position]) 
    position += 1;     
            if (position != strt) 
                { 
                    int temp = element; 
      element = a[position]; 
      a[position] = temp;   
    } 
            rotate( position, element, a, strt);
      System.out.print("After Sorting  : "); 
            for (int i =0; i<n; i++) 
    System.out.print(a[i] + " "); 
  }
    }
}
