#include <cstdio>
int main() {
    int n, m, i, j;
    char str[101];
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        for (j = 0; j < m; j++)
            if (str[j] == '.')
                if ((i ^ j) & 1) str[j] = 'W';
                else str[j] = 'B';
        printf("%s\n", str);
    }
    return 0;
}