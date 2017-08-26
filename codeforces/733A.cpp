#include <cstdio>
char allow[256], s[128];
int main() {
    int ma = 0, i, p = -1;
    allow['A'] = allow['E'] = allow['I'] = allow['O'] = allow['U'] = allow['Y'] = 1;
    scanf("%s", s);
    for (i = 0; s[i]; ++i) {
        if (allow[s[i]]) {
            if (ma < i - p) ma = i - p;
            p = i;
        }
    }
    if (ma < i - p) ma = i - p;
    printf("%d", ma);
    return 0;
}