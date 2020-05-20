import java.util.Scanner;
import java.util.stream.*;
import java.util.Arrays;
  
public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    final int n = sc.nextInt();
    int[] a = new int[n];
    for( int i=0; i<n; ++i ){ a[i] = sc.nextInt(); }

    int ans = Integer.MIN_VALUE;
    for( int i=0; i<n; ++i ){
      int taMax = Integer.MIN_VALUE;
      int aoMax = Integer.MIN_VALUE;
      for( int j=0; j<n; ++j ){
        if ( i == j ) continue;
        final int l = Math.min(i,j);
        final int r = Math.max(i,j);
        int ta = 0;
        int ao = 0;
        for( int k=l; k<=r; ++k ){
          if ( (k-l)%2 == 0 ){
            ta += a[k];
          } else {
            ao += a[k];
          }
        }

        if ( aoMax < ao ){
          aoMax = ao;
          taMax = ta;
        }
      }
      
      ans = Math.max( ans, taMax );
    }

    System.out.println( ans );
  }
  
}