//Filename count21.java
//Written by <Sili Guo>
//Written on <01/22/2017>
// Explanation: Computer will win the game mostly; but there is one way that player can win the game is to follow
// the steps to raise total to: 5-9-13-17-21. 
package count21;

//import for input and random numbers
import java.util.Scanner;
import java.util.*;

public class Count21 {
	public static void main(String[] args) {
		// Declare variables
		int numP, numC;// Hold the numbers for player and computer enters.
		int total = 0;// Hold the number for total.
		int start;// Hold the random number for who starts first
		Scanner input = new Scanner(System.in);
		Random ran = new Random();
		final int START = 2;
		final int COMPUTER = 2;

		// Explaining rules
		System.out.println("The Count 21 Game");
		System.out.println("Rules: Two players take turns entering a 1, 2, or 3, which is added to a running total,");
		System.out.println("       The player who adds the value that makes the total exceed 21 loses the game.");
		System.out.println(" ");
		System.out.println("Start the game, Randomly pick who starts first.");
		// Randomly choose who starts first
		start = ran.nextInt(START);
		// Use switch case to start
		switch (start) {
		// Computer starts first
		case 0:
			System.out.println("Computer starts first.");
			System.out.println(" ");
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
			} // end block for while loop
			break;

		// Player starts first
		case 1:
			System.out.println("You start first.");
			System.out.println(" ");
			// Player's first turn
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
			// Computer's first turn
			if (total == 1) {
				numC = ran.nextInt(COMPUTER) + 1;
				total += numC;
				System.out.println("Computer pick the number " + numC);
				System.out.println("The total now is " + total);
				System.out.println(" ");

				// The rest turns
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
						if (total == 5 || total == 9 || total == 13 || total == 17 || total == 21) {
							numC = ran.nextInt(COMPUTER) + 1;
							total += numC;
							System.out.println("Computer pick the number " + numC);
							System.out.println("The total now is " + total);
							System.out.println(" ");
						} // end block for if statement
						else {
							for (int i = 0; i < 5; i++) {
								if (total < 5 + i * 4) {
									numC = 5 + i * 4 - total;
									break;
								}
							} // end block of for loop
							total += numC;
							System.out.println("Computer pick the number " + numC);
							System.out.println("The total now is " + total);
							System.out.println(" ");
						} // end block for else block
					}
				} // end block for while loop
			} else if (total != 1) { // Computer's first turn
				numC = 5 - numP;
				total += numC;
				System.out.println("Computer pick the number " + numC);
				System.out.println("The total now is " + total);
				System.out.println(" ");
			}
			// The rest turns
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
			} // end block for while loop
		} // end block for switch case
	}
}
