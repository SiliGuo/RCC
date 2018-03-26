package count21;

import java.util.Scanner;

public class Count21 {
	public static void main(String[] args) {
		// Declare variables
		int numP, numC;
		int total = 0;
		Scanner input = new Scanner(System.in);

		// Explaining rules
		System.out.println("The Count 21 Game");
		System.out.println("Rules: Two players take turns entering a 1, 2, or 3, which is added to a running total,");
		System.out.println("       The player who adds the value that makes the total exceed 21 loses the game.");
		System.out.println(" ");
		System.out.println("Start the game, computer first pick a number.");
		numC = 1;
		total += numC;
		System.out.println("Computer pick the number " + numC);
		System.out.println("The total now is " + total);
		System.out.println(" ");

		// Loop until total exceed 21
		while (total <= 21) {
			// The player's turn
			do {
				System.out.print("Please choose a number from 1, 2, and 3: ");
				numP = input.nextInt();
				// Test for validation
				if (numP != 1 && numP != 2 && numP != 3)
					System.out.println("Invalid input. The number can only be 1, 2, or 3.");
			} while (numP != 1 && numP != 2 && numP != 3);
			total += numP;
			System.out.println("You pick the number" + numP);
			System.out.println("The total now is " + total);
			System.out.println(" ");
			// Decision for win or lose
			if (total > 21)
				System.out.println("The total exceed 21, you lose the game.");
			else {
				// Computer's turn
				numC = 4 - numP;
				total += numC;
				System.out.println("Computer pick the number " + numC);
				System.out.println("The total now is " + total);
				System.out.println(" ");
				// Decision for win or lose
				if (total > 21)
					System.out.println("The total exceed 21, you win the game.");
			}

		}
	}
}
