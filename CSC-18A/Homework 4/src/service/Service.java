//Filename Service.java
//Written by <Sili Guo>
//Written on <01/29/2017>
package service;

public class Service {
	// Declare variables
	private String description;
	private double price;
	private int time;
	
	// Constructor
	public Service(String d, double p, int t){
		description = d;
		price = p;
		time = t;
	}
	public Service(){
		description = " ";
		price = 0.0;
		time = 0;
	}
	
	// Get functions
	public String getDescripton(){
		return description;
	}
	public double getPrice(){
		return price;
	}
	public int getTime(){
		return time;
	}
}
