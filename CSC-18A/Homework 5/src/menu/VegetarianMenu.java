//Filename VegetarianMenu.java
//Written by <Sili Guo>
//Written on <02/05/2017>
package menu;

public class VegetarianMenu extends Menu{
	String[] vegEntreeChoice = {"Spinach Lasagna", "Cheese Enchiladas", "Fruit Plate"};
	
	public VegetarianMenu(){
		super();
		for(int x = 0; x < vegEntreeChoice.length; ++x){
			entreeChoice[x] = vegEntreeChoice[x];
		}
	}
}
