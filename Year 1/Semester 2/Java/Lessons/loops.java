import java.util.Scanner;

public class loops {

    public static void main(String[] args) {
        // for loops 
        int arr[] = {1, 4, 5, 7, 8, 5 ,10};

        for (int i = 0; i <= arr.length; i++ ) {
            System.out.println(i);

            if (arr[i] == 5) {
                System.out.println("Found 5 at index " + i);
                
            }  
        }
        // new loop
        String[] names = new String[5];

        // count the index
        int count = 0;
        for (String element:names) {
            System.out.println(element + " " + count);
            count++;
        }
        Scanner sc = new Scanner(System.in);
        for (int i =0;i < names.length; i++) {
            System.out.println("Input: ");
            String input = sc.nextLine();
            names[i] = input; 
            // break;   
        }

        // while loop
        Scanner ac = new Scanner(System.in);
        int x = 0;
        while (x != 10) { 
            System.out.println("Type 10");
            System.out.print("Input a number: ");
            x = ac.nextInt();  
        }


        // Do while loop

        do { 
            System.out.print("Input a number: ");
            x = ac.nextInt(); 
        } while (x != 10);

    }
}




