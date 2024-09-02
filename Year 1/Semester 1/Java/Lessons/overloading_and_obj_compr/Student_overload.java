package overloading_and_obj_compr;

public class Student_overload implements Comparable<Student> {
    // The Comparable interface allows us to compare two objects

    private String name;
    
    public Student_overload(String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Student_overload other = (Student_overload) obj;
        return this.name.equals(other.name);
    }

    @Override
    public int compareTo(Student other) {
        return this.name.compareTo(other.name);
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Setter for name
    public void setName(String name) {
        this.name = name;
    }

    public String toString() {
        return "Student(" + this.name +")";
    }


}

