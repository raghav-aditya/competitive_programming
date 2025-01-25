import java.io.* ;
import java.util.* ;

 class my_java {
    public static void main(String... args) {
        try {
            // Set input to read from "input.txt" and output to write to "output.txt"
            System.setIn(new FileInputStream("input.txt"));
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            return;
        }

        // Create Scanner object to read from input file
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Print to output file
        System.out.println(n);
        
        // Close the scanner    
        sc.close();
    }
}
