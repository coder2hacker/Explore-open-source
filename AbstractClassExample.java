abstract class Shape{
	//abstract method
	abstract void draw();
	abstract void area();
	//non-abstract method
	void same() {
		System.out.println("Same for all");
	}
	/*
	 *	To write a method without body,
	 *	add 'abstract' before method name. 
	 *
	 *	An abstract class may contain more than one abstract methods and
	 *	non-abstract methods also.
	 *	
	 *	For Non-Abstract method,
	 *  the method will be inherited but no need to write further definition.
	 *  
	 *  For Abstract method,
	 *  We have to write further definition.
	 */
}
abstract class Ellipse extends Shape{
	
}
/*
 * If a child does not implement all the abstract methods of abstract parent class,
 * then the child class must need to be declared abstract as well. 
 */
class Rectangle extends Shape{
	void draw() {
		System.out.println("Rectangle Drawing");
	}
	void area() {
		System.out.println("Rectangle Area");
	}
}
/*
 * When Rectangle class inherits an abstract class "Shape",
 * then Rectangle class must contain those abstract methods with body.
 * 
 * Without implementation of abstract method will generate error.
 */
class Circle extends Shape{
	void draw() {
		System.out.println("Circle Drawing");
	}
	void area() {
		System.out.println("Circle Area");
	}
}
public class AbstractClassExample {

	public static void main(String[] args) {
		//Shape s = new Shape();
		/*
		 * We cannot instantiate the abstract class that means 
		 * we can't create any object of an abstract class
		 */
		Shape rec = new Rectangle();
		Shape cir = new Circle();
		/*
		 * Rectangle is a sub-Category of Shape. 
		 * Circle is a sub-Category of Shape.
		 */
		rec.draw();
		rec.area();
		rec.same();
		
		cir.draw();
		cir.area();
		cir.same();
	}

}
/*
 * Why we can't create object of abstract class?
 * Abstract contains abstract or non abstract methods. And we know 
 * abstract method does not have any definition in abstract class.
 * So, creating an object of abstract class and calling abstract method
 * by that object has no implementation. So, JAVA does not allow.
 */
