//Filename SecretPhrase.java
//Written by <Sili Guo>
//Written on <01/29/2017>
package secretPhrase;

import java.util.Scanner;
import javax.swing.JOptionPane;

public class SecretPhrase {
	public static void main(String[] args) {
		// Declare variables
		StringBuilder phrase = new StringBuilder("G* T***");
		StringBuilder success = new StringBuilder("Go Team");
		Scanner input = new Scanner(System.in);
		char guess;

		// Display the hidden phrase
		// System.out.println("The hidden phrase is: " + phrase);
		System.out.println("Here starts the guessing game:");
		System.out.println(" ");
		System.out.println("Please guess for a letter.");
		System.out.println("Note: If you enter more than one letter, only first one count.");

		// Looping for guesses
		while (!phrase.toString().equals(success.toString())) {
			// Prompt user for guesses
			System.out.println("The hidden phrase is: " + phrase);
			System.out.print("Your guess is: ");
			guess = input.next().charAt(0);

			// Test for existence
			int index;
			index = success.toString().indexOf(Character.toLowerCase(guess));
			if (index >= 0) {
				phrase.setCharAt(index, Character.toLowerCase(guess));
				// System.out.println("The hidden phrase is: " + phrase);
			} else
				System.out.println("Your guessed letter is not in the phrase.");
			System.out.println(" ");
		}
		JOptionPane.showMessageDialog(null, "Congratulation! You deduced the entire phrase.");
	}
}
