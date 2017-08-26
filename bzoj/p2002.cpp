#include <cstdio>
#include <cstring>
#define MAXN 200005

int l[MAXN], r[MAXN], s[MAXN], fa[MAXN], root[MAXN];

void splay(int i) {
    while (!root[i]) {
        int j = fa[i], z;
        if (i == l[j]) z = l[j], l[j] = r[z], fa[l[j]] = j, r[z] = j;
        else z = r[j], r[j] = l[z], fa[r[j]] = j, l[z] = j;
        if (j == l[fa[j]]) l[fa[j]] = z;
        else if(j == r[fa[j]]) r[fa[j]] = z;
        fa[z] = fa[j]; fa[j] = z;
        root[z] ^= root[j];
        root[j] ^= root[z];
        s[j] = s[l[j]] + s[r[j]] + 1;
        s[z] = s[l[z]] + s[r[z]] + 1;
    }
}

void access(int i) {
    for (splay(i); fa[i] != 0; splay(i)) {
        int z = fa[i]; splay(z);
        root[r[z]] = 1; root[i] = 0;
        r[z] = i; s[z] = s[l[z]] + s[r[z]] + 1;
    }
}

int main() {
    int i, task, z, n, j, k;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", fa+i); fa[i]++;
        if (fa[i] > n) fa[i] = n+1;
    }
    for (i = 1; i <= n + 1; i++) s[i] = 1;
    memset(root, 1, sizeof(root));
    scanf("%d", &task);
    while(task-- > 0) {
        scanf("%d", &z);
        if (z == 1) {
            scanf("%d", &i); i++;
            access(i);
            printf("%d", s[l[i]]);
        } else {
            scanf("%d%d", &j, &k);
            splay(++j);
            fa[l[j]] = fa[j];
            root[l[j]] = 1;
            l[j] = 0; s[j] = s[r[j]] + 1;
            fa[j] = j + k;
            if (fa[j] > n) fa[j] = n + 1;
        }
    }
    return 0;
}