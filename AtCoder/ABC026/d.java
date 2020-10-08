import java.util.Scanner;
import java.util.stream.*;
import java.util.Arrays;
import java.util.function.Function;
  
public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    final int a = sc.nextInt();
    final int b = sc.nextInt();
    final int c = sc.nextInt();

    double l = 0d;
    double r = 200d;

    Function<double,double> f = ( p ) -> {
      return (double)a*p + (double)b*Math.sin( (double)c * p * Math.PI );
    };

    //while( l-r < 1.0e-){
      //if 
    //}

    System.out.println( l );
  }
  
}