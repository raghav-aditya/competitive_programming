public class Learn 
{
    public static void main( String args[] ){

        try{
            System.setIn( new FileInputStream( "input.txt") );
            System.setOut( new PrintStream( new FileOutputStream("output.txt")))
        } catch (Exception e) {
            System.out.println("error");
        }

        Scanner sc = new Scanner( System.in );
    } 
}
