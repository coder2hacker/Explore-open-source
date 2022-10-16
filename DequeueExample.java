import java.util.LinkedList;
import java.util.Scanner;
public class DequeueExample {

	public static void main(String[] args) {
		LinkedList<String> Queue = new LinkedList<String>();
		/*
		 * What is DeQueue?
		 * DeQueue stands for Double Ended Queue that means elements 
		 * can be inserted or deleted from both the end.
		 * 
		 * Operations
		 * 1. Insert_first : Add an element at the start of Queue.
		 * 2. Insert_last  : Add an element at the end of Queue.
		 * 3. Delete_first : Remove an element from the first of Queue.
		 * 4. Delete_last  : Remove an element from the end of Queue.
		 * 3. Display      : Print the all elements in a Queue. 
		 * 
		 * Input Restricted DeQueue:
		 * 1. Insert_last  : Add an element at the end of Queue.
		 * 2. Delete_first : Remove an element from the first of Queue.
		 * 3. Delete_last  : Remove an element from the end of Queue.
		 * 4. Display      : Print the all elements in a Queue. 
		 * 
		 * Output Restricted DeQueue:
		 * 1. Insert_first : Add an element at the start of Queue.
		 * 2. Insert_last  : Add an element at the end of Queue.
		 * 3. Delete_first : Remove an element from the first of Queue.
		 * 4. Display      : Print the all elements in a Queue. 
		 */
		Scanner sc = new Scanner(System.in);
		System.out.println("Total numbers of elements: ");
		int maxsize = sc.nextInt();
		System.out.println("Total numbers of elements: "+maxsize);
		boolean n=true;
		while(n) {
			System.out.println("1.Insert_last 2.Delete_first 3.Display 4.Quit 5.Insert first 6.Delete_last");
			//Scanner sc = new Scanner(System.in);
			System.out.print("Enter your choice: ");
			int choice = sc.nextInt();
			switch(choice) {
			case 1: if(Queue.size()==maxsize)
						System.out.println("Queue is full");
					else
					{
						System.out.println("Enter a String as Input: ");
						String val = sc.next();
						Queue.addLast(val);
						System.out.println("Your Queue: "+Queue);
					}
					break;
			case 2: if(Queue.size()==0)
						System.out.println("Queue Empty");
					else
						System.out.println("Deleting: "+Queue.removeFirst());
					break;
			case 3: System.out.println(Queue);
					break;
			case 4: sc.close();
					n=false;
					break;
			case 5: if(Queue.size()==maxsize)
						System.out.println("Queue is full");
					else
					{
						System.out.println("Enter a String as Input: ");
						String val1 = sc.next();
						Queue.addFirst(val1);
						System.out.println("Your Queue: "+Queue);
					}
			  		break;
			case 6: if(Queue.size()==0)
						System.out.println("Queue is Empty");
					else
						System.out.println("Deleting: "+Queue.removeLast());
			  		break;
			}
		}
		//Insert Operation
		Queue.addLast("Sun");
		Queue.addLast("Mon");
		Queue.addLast("Tues");
		Queue.addLast("Wednes");
		Queue.addLast("Thurs");
		
		//Print the Queue
		System.out.println("The elements within Queue: "+Queue);
		
		//Delete Operation
		System.out.println("Delete() : "+Queue.removeFirst());
		System.out.println("Delete() : "+Queue.removeFirst());
		System.out.println("The elements within Queue : "+Queue);
		
		//Display Operation
		System.out.println("Display : "+Queue);
		
	}

}
