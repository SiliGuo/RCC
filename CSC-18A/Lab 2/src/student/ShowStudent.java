//Filename Student.java
//Written by <Sili Guo>
//Written on <01/15/2017>
package student;

// import for input
import java.util.Scanner;

public class ShowStudent {
	public static void main(String[] args) {
		// declare an object
		Student student;
		student = getStudentInfo();
		student.display();
	}

	public static Student getStudentInfo() {
		// declare variables
		Student temp = new Student();
		int id, hour, point;
		Scanner input = new Scanner(System.in);
		// promote user for info, and set values to object
		System.out.print("Enter Student ID >> ");
		id = input.nextInt();
		temp.setId(id);
		System.out.print("Enter Credit Hours >> ");
		hour = input.nextInt();
		temp.setHour(hour);
		System.out.print("Enter Number of Points >> ");
		point = input.nextInt();
		temp.setPoint(point);
		temp.calAve();
		return temp;

	}
}
