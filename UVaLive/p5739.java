import java.util.*;
import java.util.stream.Collectors;

public class p5739 {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        int kase = 0;
        while (true) {
            int n = scanner.nextInt(), maxlen = scanner.nextInt();
            if (n == 0 && maxlen == 0) break;
            scanner.nextLine();
            HashSet<String> set = new HashSet<>();

            System.out.printf("Case %d\n", ++kase);

            while (--n >= 0) {
                String name = scanner.nextLine();
                String[] names = name.split(" ");
                String first = names[0];
                String last = names[names.length - 1];
                String original = new StringBuilder().appendCodePoint(first.toLowerCase().chars()
                        .filter(Character::isAlphabetic)
                        .findFirst().getAsInt())
                        .append(last.toLowerCase().codePoints().filter(Character::isAlphabetic).collect(StringBuilder::new,
                        StringBuilder::appendCodePoint, StringBuilder::append)
                        .toString()).toString();

                if (original.length() > maxlen)
                    original = original.substring(0, maxlen);
                String ans = original;
                
                int len = 1, roll = 0, sq = 1;
                while (set.contains(ans)) {
                    ++roll;
                    if (roll >= sq * 10) {
                        ++len; sq *= 10;
                    }

                    if (maxlen - len > original.length())
                        ans = original + roll;
                    else
                        ans = original.substring(0, maxlen - len) + roll;
                }
                set.add(ans);
                System.out.println(ans);
            }
        }
    }
}