package classes;

public class discussion {
    public static void main(String[] args) {

        // object 1
        university micheal = new university("tuks", 1900);
        micheal.speak();

        // object 2
        university matthew = new university("su", 1899);
        matthew.speak();

        // object 3
        university boble = new university("uct", 1910);
        boble.speak();

        // call it again !duplication
        micheal.speak();

        // 
        int x = micheal.getYear();
        System.out.println(x);

        // change the age
        micheal.setYear(2400);
        micheal.speak();

        // boble.graduate();  cant call this as its a private method!
    }
}
