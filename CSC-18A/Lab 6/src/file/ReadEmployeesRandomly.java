//Filename ReadEmployeeRandomly.java
//Written by <Sili Guo>
//Written on <02/09/2017>
package file;

import java.nio.file.*;
import java.io.*;
import java.nio.channels.FileChannel;
import java.nio.ByteBuffer;
import static java.nio.file.StandardOpenOption.*;
import java.util.Scanner;

public class ReadEmployeesRandomly {
	public static void main(String[] args) {
		Scanner keyBoard = new Scanner(System.in);
		Path file = Paths.get("RandomEmployees.txt");
		String s = "000,       ,00.00" + System.getProperty("line.separator");
		final int RECSIZE = s.length();
		byte[] data = s.getBytes();
		ByteBuffer buffer = ByteBuffer.wrap(data);
		FileChannel fc = null;
		String idString;
		int id;
		final String QUIT = "999";
		try {
			fc = (FileChannel) Files.newByteChannel(file, READ, WRITE);
			System.out.print("Enter employee ID number or " + QUIT + " to quit >> ");
			idString = keyBoard.nextLine();
			while (!idString.equals(QUIT)) {
				id = Integer.parseInt(idString);
				buffer = ByteBuffer.wrap(data);
				s = new String(data);
				System.out.println("ID #" + id + " " + s);
				System.out.print("Enter employee ID number or " + QUIT + " to quit >> ");
				idString = keyBoard.nextLine();
			}
			fc.close();
		} catch (Exception e) {
			System.out.println("Error message: " + e);
		}
	}
}