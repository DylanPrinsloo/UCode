import java.util.Scanner;

public class conditions {
    
    // conditions and booleans
    public static void main(String[] args) {
        
        int x = 6;
        int y = 9;
        int z = 20;

        String xa = "hello";
        String ya = "hi";

        // > < == != >= <=
        // boolean compare = x == y;
        // boolean compare = xa == ya;

        // chain operators 
        // boolean compare = x > y && z < y;
        // boolean compare = x > y || z < y;
        // boolean compare = !(x > y || z < y);

        // ya.equals("hello");

        boolean compare = (x > y && z < y) || (x + 7 > y || z < y);


        System.out.println(compare);
    }
}
