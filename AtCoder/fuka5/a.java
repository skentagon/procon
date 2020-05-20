import java.util.Scanner;
import java.util.stream.*;
import java.util.Arrays;
  
public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while(true){
      final int n = sc.nextInt();
      final int k = sc.nextInt();
      if ( n == 0 && k == 0 )return;
      int[] x = new int[n];
      
      for( int i=0; i<n; ++i ){ x[i] = sc.nextInt(); }
      Arrays.sort(x);

      System.out.println(
        IntStream.of(x).limit(k).sum()
      );
    }

  }
  
}