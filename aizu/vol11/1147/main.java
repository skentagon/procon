import java.util.Scanner;
import java.util.stream.*;
import java.util.Arrays;
  
public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while(true){
      final int n = sc.nextInt();
      if ( n == 0 )break;
      int max = sc.nextInt();
      int min = max;
      int sum = max;
      for( int i=1; i<n; ++i ){
        int s = sc.nextInt();
        if ( max < s ){ max = s; }
        if ( s < min ){ min = s; }
        sum += s;
      }
      System.out.println( (sum-max-min)/(n-2) );
    }
  }
  
}