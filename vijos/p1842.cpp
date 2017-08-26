#include <stdio.h>
#include <stdlib.h>

#define N 100005

struct node {
    int data, no;
} a[N], b[N];
int c[N], l[N];
int n;

inline int cmp(const void *a, const void *b) {
    node *aa = (node *)a;
    node *bb = (node *)b;
    if (aa->data == bb->data) {
        return (aa->no - bb->no);
    } else {
        return (aa->data - bb->data);
    }
}

inline int lowbit(int i) {
    return i & (-i);
}

inline void add(int p, int value) {
    for(int i = p; i <= n; i += lowbit(i)) {
        c[i] += value;
    }
}

inline int sum(int p) {
    int s = 0;
    for (int i = p; i > 0; i -= lowbit(i)) {
        s += c[i];
    }
    return s;
}

int main() {
    int i, ans = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i].data);
        a[i].no = i;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i].data);
        b[i].no = i;
    }
    qsort(a, n, sizeof(a[0]), cmp);
    qsort(b, n, sizeof(b[0]), cmp);
    for (i = 0; i < n; i++) {
        l[b[i].no] = a[i].no;
    }
    for (i = 0; i < n; i++) {
        add(l[i]+1, 1);
        //printf("OAO%d\n",sum(l[i]+1));
        ans = (ans + i + 1 - sum(l[i]+1)) % 99999997;
    }
    printf("%d\n", ans);
    return 0;
}