package pkg031716;

public class Main {

    public static void main(String[] args) {
    int x; // some integer x
    
    // prompt for a value of x and fetch the value from the keyboard
    System.out.print("Enter an integer value for X: ");
    x = new java.util.Scanner( System.in) .nextInt();
    
    int y; // some integer y
    int z; // some integer z
    
     // if x > 0 we set y to 10, otherwise set y to 5.
    if (x>0)
    {
        y=10;
        z=4;
    }
    else 
    {
        y=5;
        z=1;
    }
    
    // demonstrate using conditional operator ?: to do the same thing as line 14 through 22
    //x>0? y=10: y=5;
    //x>0? z=4: z=1;
    //x>0? (y=10, z=4): (y=5,z=1);
    //y= x>0? 10:5;
    
    // output results
    System.out.print("x is " + x + ", and y is " + y);
    System.out.println(", and z is " + z );
    }
    
}
