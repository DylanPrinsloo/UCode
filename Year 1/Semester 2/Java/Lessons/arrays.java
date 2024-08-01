import java.util.Scanner;
import java.util.Arrays;

public class arrays {
    public static void main(String[] args) {
        
        // int[] newArr = new int[5];
        String[] newArr = new String[5];

        newArr[0] = "hello1";
        newArr[1] = "hello2";
        newArr[2] = "hello3";
        newArr[3] = "hello4";
        newArr[4] = "hello5";

        int[] number = {2,4,7,8,10};

        int a = number[3];
        System.out.println(a);


        int[] x = {-88, 54, 43, 23, 25, 88};

        Arrays.sort(x, 1, 7);  // sorting an array or sort(x)

        for ( int i:x) {
            System.out.println(i + ",");
        }  
    }
    
}
