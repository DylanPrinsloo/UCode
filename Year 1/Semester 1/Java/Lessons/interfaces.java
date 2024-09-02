public class interfaces {
    
    // Define an interface
public interface Animal {
    void makeSound();
    void move();
}

// Implement the interface in a class
public class Dog implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }

    @Override
    public void move() {
        System.out.println("The dog runs.");
    }
}

// Another implementation of the interface
public class Cat implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }

    @Override
    public void move() {
        System.out.println("The cat sneaks.");
    }
}

public class Main {
    public static void main(String[] args) {
        // Creating instances of Dog and Cat
        Animal dog = new Dog();
        Animal cat = new Cat();

        // Calling interface methods
        dog.makeSound();
        dog.move();
        
        cat.makeSound();
        cat.move();
    }
}

    
}

// Why And When To Use Interfaces?

// 1) To achieve security - hide certain details and only show the important details of an object (interface).

// 2) Java does not support "multiple inheritance" (a class can only inherit from one superclass).
//  However, it can be achieved with interfaces, because the class an implement multiple interfaces. 
// Note: To implement multiple interfaces, separate them with a comma.
