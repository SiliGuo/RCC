//Filename State.java
//Written by <Sili Guo>
//Written on <01/15/2017>
package state;

public class TestState {
	public static void main(String[] args) {
		State California = new State("California", 39250017, "Sacramento", 466488, "Los Angeles", 3971883);
		State Florida = new State("Florida", 20612439, "Tallahassee", 181376, "Orlando", 238300);
		// Output Result of two states
		System.out.println("State Information Report");
		System.out.println("State Name:               " + California.getSateName());
		System.out.println("Population:               " + California.getStatePopulation());
		System.out.println("Capital Name:             " + California.getCapitalName());
		System.out.println("Population:               " + California.getCapitalPopulation());
		System.out.println("Most Popular City Name:   " + California.getMostPopName());
		System.out.println("Population:               " + California.getMostPopPopulation());
		System.out.println("");
		System.out.println("State Information Report");
		System.out.println("State Name:               " + Florida.getSateName());
		System.out.println("Population:               " + Florida.getStatePopulation());
		System.out.println("Capital Name:             " + Florida.getCapitalName());
		System.out.println("Population:               " + Florida.getCapitalPopulation());
		System.out.println("Most Popular City Name:   " + Florida.getMostPopName());
		System.out.println("Population:               " + Florida.getMostPopPopulation());

	}

}
