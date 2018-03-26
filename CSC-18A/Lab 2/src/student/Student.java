//Filename Student.java
//Written by <Sili Guo>
//Written on <01/15/2017>
package student;

public class Student {
	private int id;
	private int hour;
	private int point;
	private double average;

	// Constructor
	public Student() {
		id = 9999;
		hour = 3;
		point = 12;
		average = calAve();
	}

	// Mutators and accessors
	public int getId() {
		return id;
	}

	public void setId(int i) {
		id = i;
	}

	public int getHour() {
		return hour;
	}

	public void setHour(int h) {
		hour = h;
	}

	public int getPoint() {
		return point;
	}

	public void setPoint(int p) {
		point = p;
	}

	public double calAve() {
		average = (1.0 * point) / hour;
		return average;
	}

	public void display() {
		System.out.println("Student ID: " + id);
		System.out.println("Credit Hours: " + hour);
		System.out.println("Number of Points: " + point);
		System.out.println("Grade Point Ave: " + average);
	}
}
