package collectionsframework;

import java.util.ArrayList;
import java.util.Iterator;

public class ArrayListDemo {

	public static void main(String[] args) {
		// instantiate an array list
		ArrayList<String> countriesList = new ArrayList<String>(); // default size 10
		
		/* Some important method
		 * clear() contains(Object o) get(int index) indexOf(Object o) isEmpty()
		 * remove(int index) remove(Object o) removeRange(int fromIndex, int toIndex)
		 * set(int index, E element) toArray()
		 */

		
		countriesList.add("India");
		countriesList.add("Bhutan");
		countriesList.add("France");
		countriesList.add("Usa");
		
		countriesList.add(4, "Egypt");
		countriesList.add(5, "Spain");
		countriesList.add(6, "Canda");
		countriesList.add(7, "oman");
		countriesList.add(8, "Uk");
		countriesList.add(9,"Zimbambe");
		
		countriesList.add("Mexico");
		
	
		
		//countiesList.add(new Employee // genric  
		
		// obtain the iterator
		Iterator<String> itr = countriesList.iterator();
		
		
		
		while(itr.hasNext())
			System.out.println(itr.next());	
		
		System.out.println("Printing Friends list");
		
		
		ArrayList<String> friendsList = new ArrayList<String>();
		
		friendsList.add("Shbham");
		friendsList.add("Samu");
		friendsList.add("Sudhir");
		
       Iterator<String> itr2 = friendsList.iterator();
		
		
		
		while(itr2.hasNext())
			System.out.println(itr2.next());	
		

	}
	
	

}
