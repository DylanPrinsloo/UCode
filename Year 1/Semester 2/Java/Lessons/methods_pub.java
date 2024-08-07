import java.util.Scanner;


public class methods_pub {
    
    public static void details(String n, String b, String c) {
        System.out.println("Hello " + n + b + ". Your Student Id is: " + c);

    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Please enter your name.");
        String name = input.next();
        System.out.println("Please enter your surname.");
        String surname = input.next();
        System.out.println("Please enter your student ID.");
        String studentId = input.next();

        details(name, surname, studentId);

        System.out.println("You have entered your detials");
        input.close();
        
    }
    }
    
