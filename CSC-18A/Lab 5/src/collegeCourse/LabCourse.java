//Filename LabCourse.java
//Written by <Sili Guo>
//Written on <02/05/2017>
package collegeCourse;

public class LabCourse extends CollegeCourse{
	// Constructor
	public LabCourse(String dep, int cn, int cd) {
		super(dep, cn, cd);
		fee += 50;
	}
	
	// Override display method
	public void display(){
		super.display();
	}
}
