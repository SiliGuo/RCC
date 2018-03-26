//pg.191 Overloading method (Incorrect form)
package callSimpleMethod;

public class CallSimpleMethod {
	public static void main(String[] args) {
		double doubleValue = 45.67;
		int intValue = 17;
		simpleMethod(doubleValue);
		simpleMethod(intValue);
	}

	public static void simpleMethod(double d) {
		System.out.println("Method receives double parameter");
	}
}
