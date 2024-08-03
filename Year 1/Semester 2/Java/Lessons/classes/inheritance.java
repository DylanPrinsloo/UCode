package classes;

public class inheritance extends university {
// inheritance is achieved with the 'extends' keyword, identical to the university class
    private int ranking;

    // Constructor for Inheritance class
    public inheritance(int year, String name, int ranking) {
        super(name, year); // 'super' calls the constructor of the superclass (University)
        this.ranking = ranking;
    } 

    // Another constructor with a default ranking
    public inheritance(String name, int year) {
        super(name, year); // 'super' calls the constructor of the superclass (University)
        this.ranking = 50; // default ranking value
    }

    // Method to modify the ranking
    public void number(int x) {
        this.ranking -= x; // Adjust ranking by subtracting x
    }

    // Getter for ranking
    public int getRanking() {
        return ranking;
    }

    // Setter for ranking
    public void setRanking(int ranking) {
        this.ranking = ranking;
    }

    // protected - similar to public, it only allows things in the same package to access it.
    protected void university(String name) {
        this.name = name;
    }
}
