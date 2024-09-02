public class enumerations {
    // Define an enum
public enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
}

// Using the enum in a class
public class EnumExample {
    
    // Method to demonstrate the use of enums
    public void printDayMessage(Day day) {
        switch (day) {
            case MONDAY:
                System.out.println("Start of the work week!");
                break;
            case TUESDAY:
                System.out.println("Second day of the work week.");
                break;
            case WEDNESDAY:
                System.out.println("Midweek day.");
                break;
            case THURSDAY:
                System.out.println("Almost the weekend.");
                break;
            case FRIDAY:
                System.out.println("Last work day of the week!");
                break;
            case SATURDAY:
                System.out.println("Weekend fun day!");
                break;
            case SUNDAY:
                System.out.println("Rest and relaxation day.");
                break;
        }
    }

    public static void main(String[] args) {
        // Creating an instance of EnumExample
        EnumExample example = new EnumExample();

        // Demonstrating the use of enums
        example.printDayMessage(Day.MONDAY);
        example.printDayMessage(Day.FRIDAY);
        example.printDayMessage(Day.SUNDAY);
    }
}

}
