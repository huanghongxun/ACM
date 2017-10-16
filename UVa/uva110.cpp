#include <stdio.h>
#include <string.h>
#define rep(i,j,k) for(i=j;i<k;++i)
#define FOR(i,j,k) for(i=j;i<=k;++i)
const int N = 32;
int n, path[N];

void insert(int cur, int m) {
    for (int i = m; i > cur; i--)
        path[i] = path[i - 1];
    path[cur] = m;
}

void work(int dep) {
    int i, j;
    FOR(i,0,dep) printf("  "); // indent
    if (dep == n - 1) {
        printf("writeln(%c", path[0] + 'a');
        rep(i,1,n)
            printf(",%c", path[i] + 'a');
        puts(")");
        return ;
    }

    int tmp[N];
    memcpy(tmp, path, sizeof tmp);

    for (i = dep + 1; i >= 0; i--) {
        if (i) {
            printf("if %c < %c then\n", path[i - 1] + 'a', dep + 1 + 'a');
        }
        insert(i, dep + 1);
        work(dep + 1);
        memcpy(path, tmp, sizeof tmp);
        if (i) {
            FOR(j,0,dep) printf("  "); // indent
            printf("else ");
        }
        if (i == 1) printf("\n");
    }
}

int main() {
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        memset(path, 0, sizeof path);
        scanf("%d", &n);

        printf("program sort(input,output);\nvar\na");
        for (int i = 1; i < n; i++)
            printf(",%c", 'a' + i);
        printf(" : integer;\nbegin\n  readln(a");
        for (int i = 1; i < n; i++) 
            printf(",%c", 'a' + i); 
        puts(");");

        work(0);

        puts("end.");

        if (kase)
            putchar('\n');
    }
    return 0;
}