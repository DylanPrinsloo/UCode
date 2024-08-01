import java.util.Scanner;

public class nested_states{

    public static void main(String[] args) {

        System.out.println("Input your age: ");

        Scanner entry = new Scanner(System.in);
        String s = entry.nextLine();

        int age = Integer.parseInt(s);

        if (age >= 21) {
            System.out.println("Input your favourite food: ");
            String food = entry.nextLine();

            if (food.equals("pizza")) {
                System.out.println("nice");
            }
            else {
                System.err.println("Not pizza i guess");
            }
        }
        else if (age > 13 && age < 21) {
            System.out.println("You are a teen");
            
        }
        else {
            System.out.println("You are not a teen or an adult");
        }


    }
}