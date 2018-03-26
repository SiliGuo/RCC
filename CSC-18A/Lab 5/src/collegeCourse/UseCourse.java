//Filename UseCourse.java
//Written by <Sili Guo>
//Written on <02/05/2017>
package collegeCourse;

import java.util.Scanner;

public class UseCourse {

	public static void main(String[] args) {
		// Declare variables
		Scanner input = new Scanner(System.in);
		String depart;
		int number, credit;

		// Prompt user for course info
		System.out.print("Enter the course department: ");
		depart = input.nextLine();
		System.out.print("Enter the course number: ");
		number = input.nextInt();
		System.out.print("Enter the credits for the course: ");
		credit = input.nextInt();
		
		// Making decision
		if (depart.equalsIgnoreCase("BIO") || depart.equalsIgnoreCase("CHM") || depart.equalsIgnoreCase("CIS") || depart.equalsIgnoreCase("PHY")){
			LabCourse course = new LabCourse(depart, number, credit);
			course.display();
		}
		else{
			CollegeCourse course = new CollegeCourse(depart, number, credit);
			course.display();
		}
	}
}
