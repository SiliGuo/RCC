//Filename SalonReport.java
//Written by <Sili Guo>
//Written on <01/29/2017>
package service;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.*;

public class SalonReport {
	public static void main(String[] args) {
		// Declare variables
		Scanner input = new Scanner(System.in);
		int choice, a, b, tempT;
		String tempS;
		double tempP;
		Service temp;

		// Create an array for objects
		ArrayList<Service> service = new ArrayList<Service>();

		// Initialize six objects
		Service cut = new Service("Cut", 8.00, 15);
		Service shampoo = new Service("Shampoo", 4.00, 10);
		Service manicure = new Service("Manicure", 18.00, 30);
		Service style = new Service("Style", 48.00, 55);
		Service permanent = new Service("Permanent", 18.00, 35);
		Service trim = new Service("Trim", 6.00, 5);

		// Add all six objects into the array
		service.add(cut);
		service.add(shampoo);
		service.add(manicure);
		service.add(style);
		service.add(permanent);
		service.add(trim);

		// Output the report
		System.out.println("Report Before Sorting:");
//		System.out.printf("%-29s%-19s%-14s\n", "Service Description", "Price ($)", "Time (Minutes)");
		System.out.printf("%-29s%-19s%s\n", "Service Description", "Price ($)", "Time (Minutes)");
		for (int i = 0; i < 6; i++) {
			System.out.printf("%-29s%7.2f%20d\n", service.get(i).getDescripton(), service.get(i).getPrice(),
					service.get(i).getTime());
		}
		System.out.println(" ");

		// Ask user which field he wants to sort
		System.out.println("Please choose which field you would like to sort asending:");
		System.out.println("1. Service Description\n" + "2. Price\n" + "3. Time");
		do {
			System.out.print("Choose the number(1, 2, or 3): ");
			choice = input.nextInt();
			// Check for validation
			if (choice != 1 && choice != 2 && choice != 3) {
				System.out.println("Invalid input! Please enter 1, 2, or 3.");
			}
		} while (choice != 1 && choice != 2 && choice != 3);

		// Use switch case for different choice
		switch (choice) {
		case 1: // Sort by service description
			a = 1;
			while (a < 6) {
				temp = service.get(a);
				tempS = service.get(a).getDescripton();
				b = a - 1;
				while (b >= 0 && (service.get(b).getDescripton()).compareTo(tempS) > 0) {
					service.set(b + 1, service.get(b));
					--b;
				}
				service.set(b + 1, temp);
				++a;
			}
			break;
		case 2: // Sort by price
			a = 1;
			while (a < 6) {
				temp = service.get(a);
				tempP = service.get(a).getPrice();
				b = a - 1;
				while (b >= 0 && service.get(b).getPrice() > tempP) {
					service.set(b + 1, service.get(b));
					--b;
				}
				service.set(b + 1, temp);
				++a;
			}
			break;
		case 3: // Sort by time
			a = 1;
			while (a < 6) {
				temp = service.get(a);
				tempT = service.get(a).getTime();
				b = a - 1;
				while (b >= 0 && service.get(b).getTime() > tempT) {
					service.set(b + 1, service.get(b));
					--b;
				}
				service.set(b + 1, temp);
				++a;
			}
		}// End block of switch

		// Display the result after sorting
		System.out.println("\nThe report after sorting: ");
		System.out.printf("%-29s%-19s%-14s\n", "Service Description", "Price ($)", "Time (Minutes)");
		for (int i = 0; i < 6; i++) {
			System.out.printf("%-29s%7.2f%20d\n", service.get(i).getDescripton(), service.get(i).getPrice(),
					service.get(i).getTime());
		}
		System.out.println(" ");
	}
}