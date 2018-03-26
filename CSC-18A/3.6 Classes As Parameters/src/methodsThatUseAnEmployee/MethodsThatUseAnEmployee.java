//pg.161 Classes objects can be used as parameters
package methodsThatUseAnEmployee;

import java.util.Scanner;

public class MethodsThatUseAnEmployee {
	public static void main(String[] args) {
		Employee myEmployee;
		myEmployee = getEmployeeData();
		displayEmployee(myEmployee);
	}

	public static Employee getEmployeeData() {
		Employee tempEmp = new Employee();
		int id;
		double sal;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter employee ID >> ");
		id = input.nextInt();
		tempEmp.setEmpNum(id);
		System.out.print("Enter employee salary >> ");
		sal = input.nextDouble();
		tempEmp.setEmpSalary(sal);
		return tempEmp;
	}

	public static void displayEmployee(Employee anEmp) {
		System.out.println("\nEmployee #" + anEmp.getEmpNum() + " Salary is " + anEmp.getEmpSalary());
	}
}
