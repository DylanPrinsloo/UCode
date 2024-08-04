package classes;

    public class outer_class {
        private String outerField = "Outer field";
    
        // Inner class
        public class InnerClass {
            private String innerField = "Inner field";
    
            public void display() {
                // Accessing outer class field
                System.out.println("Outer field: " + outerField);
                // Accessing inner class field
                System.out.println("Inner field: " + innerField);
            }
        }
    
        public void outerMethod() {
            // Creating an instance of the inner class
            InnerClass innerObject = new InnerClass();
            innerObject.display();
        }
    
        public static void main(String[] args) {
            // Creating an instance of the outer class
            outer_class outerObject = new outer_class();
            // Calling the outer class method, which in turn uses the inner class
            outerObject.outerMethod();
        }
    
    
}
