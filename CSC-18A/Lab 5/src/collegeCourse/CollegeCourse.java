//Filename CollegeCourse.java
//Written by <Sili Guo>
//Written on <02/05/2017>
package collegeCourse;

public class CollegeCourse {
	// Data fields
	private String department;
	private int courseNum;
	private int credits;
	protected int fee;
	
	// Constructor
	public CollegeCourse(String dep, int cn, int cd){
		department = dep;
		courseNum = cn;
		credits = cd;
		fee = 120 * credits;
	}

	// Display method
	public void display(){
		System.out.println("\nCourse Data");
		System.out.printf("%-15s%s\n", "Department:", department.toUpperCase() );
		System.out.printf("%-15s%d\n", "Course Number:", courseNum);
		System.out.printf("%-15s%d\n", "Credits:", credits);
		System.out.printf("%-15s%s%d\n", "Tuition Fee:", "$", fee);
	}
}