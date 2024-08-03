package overloading_and_obj_compr;

public class usecase_for_overloading {
    public static void main(String[] args) {
        
        Student joe = new Student("Joe");
        Student mike = new Student("Joe"); // Pay attention here
        Student dylan = new Student("Dylan");

        // System.out.println(joe == mike); false
        System.out.println(joe == mike); // This will print: false

        // The RAM sees this as correct, but we don't. We will adjust the code to work on this
        System.out.println(joe.equals(mike)); // This will print: true, because equals() is correctly overridden

        // CompareTo method
        System.out.println(joe.compareTo(mike)); // This will show 0, as both have the same name

        System.out.println(joe.compareTo(dylan)); // This will show an integer that represents the difference in lexicographical order

        // Boolean comparison
        System.out.println(joe.compareTo(mike) > 0); // This will print: false, because both names are equal
    }
}

