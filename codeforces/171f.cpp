#include <cstdio>
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}
int rev(int x) {
    int r = 0;
    for (; x; x /= 10) r = r * 10 + x % 10;
    return r;
}
int main() {
    int n, i, k = 0;
    scanf("%d", &n);
    for(i = 0; ; i++)
        if (i != rev(i) && isPrime(rev(i)) && isPrime(i))
            if (++k == n) { printf("%d", i); break; }
    return 0;
}