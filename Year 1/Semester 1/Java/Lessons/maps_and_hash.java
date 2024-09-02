import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.HashSet;
import java.util.TreeMap;
import java.util.LinkedHashMap;

public class maps_and_hash {

    public static void main(String[] args) {
        Map m = new HashMap();   // Dictionary

        m.put("Tim",200);
        m.put("Timmy","x");
        m.put("Asty",888);

        m.containsValue("Tim");
        m.containsKey(5);

        // m.get(5);
        System.out.println(m.get(5)); // null output

        // System.out.println(m.get("Tim")); // m.get is for the key
        // System.out.println(m);
        System.out.println(m.values()); 

        Map a = new TreeMap();  // same key 

        a.put("d",20);
        a.put("b",30);
        a.put("a",34);

        Map t = new LinkedHashMap();  // maintain the order we gave

        t.put("amr",2);
        t.put("sa",4);
        t.put("usa",1);

        Map poll = new HashMap();  // finding values in a string
        String str = "Hello my name is Dylan and i am cool";

        for (char x:str.toCharArray()) {
            if (m.containsKey(x)) {
                int old = (int) poll.get(x);
                poll.put(x, old+1);
            }
            else {
                poll.put(x,1);
            }
            // poll.remove(' ') // removes space for an example
            System.out.println(poll);  
        }

    }

}