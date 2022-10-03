
public class Command_Line_Argument {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		for(int i = 0;i<args.length;i++) {
			System.out.println("args["+i+"]= "+args[i]);
			//System.out.println("Welcome");
		}
		int a = Integer.parseInt(args[0]);
		/*
		 Integer.parseInt is use to typecast String to integer.
		 Here Integer is a class
		 */
		System.out.println(a);
		float f = Float.parseFloat(args[1]);
		System.out.println(f);
		
		double d = Double.parseDouble(args[2]);
		System.out.println(d);
		
		
	}

}
