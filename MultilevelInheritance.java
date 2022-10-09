class GrandClass{
	void GrandClass_display() {
		System.out.println("Grand Class");
	}
}
class BaseClass extends GrandClass{
	void BaseClass_display() {
		System.out.println("Base Class");
	}
}
class SubClass extends BaseClass{
	void SubClass_display() {
		System.out.println("Sub Class");
	}
}
public class MultilevelInheritance {

	public static void main(String[] args) {
		GrandClass g = new GrandClass();
		g.GrandClass_display();
		System.out.println();
		//GrandClass can access only it's Properties.
		 
		BaseClass p = new BaseClass();
		p.GrandClass_display();
		p.BaseClass_display();
		System.out.println();
		//BaseClass can access GrandClass and also own Properties.
		
		SubClass c = new SubClass();
		c.GrandClass_display();
		c.BaseClass_display();
		c.SubClass_display();
		//SubClass can access GrandClass, BaseClass and also own Properties.
	}

}