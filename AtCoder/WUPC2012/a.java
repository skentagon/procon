import java.util.Scanner;
import java.util.stream.*;
  
public class Main {
  
  static final int[] year = new int[]{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int ma = sc.nextInt();
    int da = sc.nextInt();
    int mb = sc.nextInt();
    int db = sc.nextInt();

    System.out.println(
      IntStream.of(year).limit(mb-1).sum()
      - IntStream.of(year).limit(ma-1).sum()
      + db - da
    );

  }
  
}