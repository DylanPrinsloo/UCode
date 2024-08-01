import java.lang.reflect.Array;
import java.util.Scanner;
import java.util.HashSet;
import java.util.Set;
// import java.util.TreeSet;
// import java.util.ArrayList;
// import java.util.LinkedHashSet;
// import java.util.LinkedList;
public class sets_and_lists {
    public static void main(String[] args) {
        Set<Integer> t = new HashSet<Integer>();
        t.add(5);
        t.add(4);
        t.add(1);
        t.add(5); // duplication

        // t.remove(5);
        // t.clear();
        // t.isempty();
        // t.size();
        // t.get();

        // t.sublist(); // gets in a certain range
        // System.out.println(t.sublist(1, 3));

        boolean x = t.contains(0); // looks for 5

        // Set<Double> t = new HashSet<Double>(w);
        // w.
        System.out.println(t);

        // Set<Integer> a = new TreeSet<Integer>(); // treeSet is ordered
        // Set,Integer> a = new LinkedHashSet<Integer>();

        // ArrayList<Integer> a = new ArrayList<Integer>();  // list 
        // a.get(1 , 5(element));

        // LinkedList<Integer> a = new LinkedList<Integer>();  // list 




    }
    
}
