#include <cstdio>

int state[] = {0, 1, 0, 1, 2};
int state_odd(int x) {
    if (x <= 4) return state[x];
    if (x & 1) return 0;
    return state_odd(x / 2) == 1 ? 2 : 1;
}

int state_even(int x) {
    if (x <= 2) return x;
    else return x & 1 ^ 1;
}

int main() {
    int ans = 0, n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, a; i < n; i++) {
        scanf("%d", &a);
        if (k & 1) ans ^= state_odd(a);
        else ans ^= state_even(a);
    }
    puts(ans ? "Kevin" : "Nicky");
    return 0;
}