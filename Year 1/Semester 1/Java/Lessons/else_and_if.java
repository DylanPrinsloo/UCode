import java.util.Scanner;

public class else_and_if {
    public static void main(String[] args) {
        
        Scanner sca = new Scanner(System.in);
        String s = sca.nextLine();
       
        if (s.equals("tim")) {
                System.out.println("The name is tim");
        }
        else if (s.equals("hello")) {
            System.out.println("hello, You typed" + s);  
        }
        else {
            System.out.println("You typed" + s);
        }
    }
    
}
