#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    long long a, b; char A = 'A', B = 'B';
    char ans[10000]; int len = 0;
    scanf("%I64d%I64d", &a, &b);
    while (a && b) {
        if (a < b) swap(a, b), swap(A, B);
        if (b == 1) {
            if (a > 1) len += sprintf(ans + len, "%I64d%c", a - 1, A);
            puts(ans);
            return 0;
        }
        len += sprintf(ans + len, "%I64d%c", a / b, A);
        a %= b;
    }
    puts("Impossible");
    return 0;
}