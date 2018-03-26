//Filename State.java
//Written by <Sili Guo>
//Written on <01/15/2017>
package state;

public class State {
	// private field
	private String stateName;
	private int statePopulation;
	private City capital;
	private City mostPop;

	// constructor
	public State(String ns, int ps, String nc, int pc, String np, int pp) {
		stateName = ns;
		statePopulation = ps;
		capital = new City(nc, pc);
		mostPop = new City(np, pp);
	}

	// accessors
	public String getSateName() {
		return stateName;
	}

	public int getStatePopulation() {
		return statePopulation;
	}

	public String getCapitalName() {
		return capital.getCityName();
	}

	public int getCapitalPopulation() {
		return capital.getCityPopulation();
	}

	public String getMostPopName() {
		return mostPop.getCityName();
	}

	public int getMostPopPopulation() {
		return mostPop.getCityPopulation();
	}

	// private class
	private class City {
		// private field
		private String cityName;
		private int cityPopulation;

		// constructor
		public City(String n, int p) {
			cityName = n;
			cityPopulation = p;
		}

		// accessors
		public String getCityName() {
			return cityName;
		}

		public int getCityPopulation() {
			return cityPopulation;
		}
	}
}
