import java.util.Scanner;

public class objects {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // sc.next();

        String h = "Hello";
        h.length();

        second("second method", 4);

        // calling to third
        System.out.println(third(20));

    } 
    // void means returns nothing
    public static void second(String str, int x) {  
        for (int i = 0; i < x; i++) {
            System.out.println(str); 
        }
        
    }

    public static int third( int x) {
        return x + 2;
        
    }
}
