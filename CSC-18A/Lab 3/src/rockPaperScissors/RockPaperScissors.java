//Filename RockPaperScissors.java
//Written by <Sili Guo>
//Written on <01/22/2017>
package rockPaperScissors;

// import for output and random numbers
import java.util.Scanner;
import java.util.*;

public class RockPaperScissors {
	public static void main(String[] args) {
		// declare variables
		int choice, computer;
		String com[] = { "Rock", "Paper", "Scissors" };
		// Prompt choice from user
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter a number representing rock, paper, or scissors.");
		System.out.println("Rock is 1, paper is 2, scissors is 3.");
		System.out.print("Your choice is (1, 2, or 3): ");
		choice = input.nextInt();
		// Computer generate a random number
		Random ran = new Random();
		final int LIMIT = 3;
		computer = ran.nextInt(LIMIT) + 1;
		// Show both choices
		System.out.println("You choose <" + com[choice - 1] + "> and computer choose <" + com[computer - 1] + ">.");
		// Compare to get the result
		if (choice == computer)
			System.out.println("The result is a tie.");
		else if (choice == 1 && computer == 3)
			System.out.println("You win the game.");
		else if (choice == 3 && computer == 1)
			System.out.println("You lose the game.");
		else if (choice > computer)
			System.out.println("You win the game.");
		else
			System.out.println("You lose the game.");

	}
}
