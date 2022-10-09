enum Apple{
	abc,xyz,mno,plu,rtg
}
/*
 * enum		: Keyword
 * Apple	: enum name 
 * 
 * Here we have defined Apple as enum.
 */
public class EnumerationExample1 {

	public static void main(String[] args) {
		Apple ap;
		 //Here, ap is an object of enum Apple. 
		ap = Apple.valueOf("mno");
		System.out.println("ap contains: "+ap);
		System.out.println();
		
		Apple allapples[] = Apple.values();
		//Here allapples[] is an array of enum apple that contains all values of Apple
		for(Apple a: allapples)
		{
			System.out.println(a);
		}
	}
}
