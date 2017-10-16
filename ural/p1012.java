import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class p1012
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      PrintWriter out = new PrintWriter(System.out);

      int n = in.nextInt();
      int k = in.nextInt();

      BigInteger dp[] = new BigInteger[n + 1];
      dp[0] = BigInteger.valueOf(1);
      dp[1] = BigInteger.valueOf(k - 1);
      for (int i = 2; i <= n; ++i)
          dp[i] = dp[i - 1].add(dp[i - 2]).multiply(dp[1]);

      out.println(dp[n]);

      out.flush();
   }
}