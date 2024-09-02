package  classes;

public class university {

    public String name;
    private int year;

    // constructor method

    public university(String name, int year) {
        // this is used
        this.name = name;
        this.year = year;
        graduate();

    }

    public void speak() {
        System.out.println("I am in the " + this.name + "and I am in year " + this.year);
    }  

    public int getYear() {
        return this.year();
    }

    // change the university or year?

    public void setYear(int year) {
        this.year = year;
    }

    // private method
    private int graduate() {
        return this.year + 2;
    }
}

// object will be created in Main - file discussion
