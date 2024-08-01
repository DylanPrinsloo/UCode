import java.util.Scanner;

public class input {

    public static void main(String[] args) {
        Scanner entry = new Scanner(System.in);
        String scanned = entry.next();
        // next input
        
        // conversion
        int x = Integer.parseInt(scanned);

        System.out.println("\n" + scanned);

    }
}