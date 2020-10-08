import java.util.Scanner;
import java.util.stream.*;
import java.util.Arrays;
  
public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while(true){
      final int n = sc.nextInt();
      final int r = sc.nextInt();
      if ( n == 0 && r == 0 )break;
      int[] a = new int[n];
      for( int i=0; i<n; ++i ){ a[i] = n-i; }
      for( int i=0; i<r; ++i ){
        final int p = sc.nextInt() - 1;
        final int c = sc.nextInt();
        int[] t = new int[p];
        for(int j=0; j<p; j++ ){ t[j]=a[j]; }
				for(int j=0; j<c; j++ ){ a[j]=a[j+p]; }
				for(int j=0; j<p; j++ ){ a[j+c]=t[j]; }
      }
      System.out.println( a[0] );
    }
  }
  
}