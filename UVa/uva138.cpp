#include <cstdio>
#include <cstring>
#include <cmath>

int main() {
    long long a, mid;
    for (int i = 2; i < 100000000; i++) {
        a = 1ll * i * (i + 1); 
        a /= 2; 
        mid = sqrt(a);
        if (mid * mid == a)
            printf("%10lld%10d\n", mid, i);
    }
    return 0;
}