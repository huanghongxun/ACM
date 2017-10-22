import java.util.*;

public class p3777 {

    static class Range implements Comparable<Range> {
        int l, r, len;

        Range(int l, int r) {
            this.l = l;
            this.r = r;
            len = r - l + 1;
        }

        public int compareTo(Range b) {
            return l == b.l ? new Integer(r).compareTo(b.r) : new Integer(l).compareTo(b.l);
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            int n = scanner.nextInt();
            if (n == 0) break;

            String[] pages = scanner.next().split(",");
            ArrayList<Range> ranges = new ArrayList<>();
            for (String page : pages) {
                int l, r;
                if (page.contains("-")) {
                    String[] nums = page.split("-");
                    l = Integer.valueOf(nums[0]);
                    r = Integer.valueOf(nums[1]);
                } else {
                    l = r = Integer.valueOf(page);
                }
                if (r > n) r = n;
                if (l <= r)
                    ranges.add(new Range(l, r));
            }

            ranges.sort(null);

            int ans = 0, mx = 0;

            if (!ranges.isEmpty()) {
                mx = ranges.get(0).r;
                ans = ranges.get(0).len;
            }

            for (int i = 1; i < ranges.size(); ++i) {
                if (ranges.get(i).r <= mx) continue;
                if (ranges.get(i).l > mx) {
                    ans += ranges.get(i).len;
                    mx = ranges.get(i).r;
                } else if (ranges.get(i).r > mx) {
                    ans += ranges.get(i).r - mx;
                    mx = ranges.get(i).r;
                }
            }

            System.out.println(ans);
        }
    }

}