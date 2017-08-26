#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define M 120
#define FOR(i,j,k) for(i=j;i<=k;i++)
using namespace std;
int n,l,m,limit;
int pos[M];
double possibility[M];
struct ACAutomaton {
    struct Node {
        Node *son[11],*fail;
        int end, id;
    } node[M], *C, *root;
    int sz;
    ACAutomaton() { sz = 0; C = root = node; }
    void insert(const char *str) {
        Node *p = root; int pos = 0, len = strlen(str);
        for (int j = 0; j < len; j++) {
            int i = str[j] - 'A' + 1;
            if (!p->son[i]) p->son[i] = ++C, p->son[i]->id = ++sz;
            pos++;
        }
        putchar('$');
        p->end = pos;
        ::pos[pos] = p->id;
    }
    void build() {
        static Node *q[M];
        int i, f = 0, r = 0;
        q[r++] = root;
        while (f < r) {
            Node *p = q[f++];
            FOR (i, 1, m) {
                Node *x = p == root ? root : p->fail->son[i];
                if (p->son[i])
                    q[r++] = p->son[i], p->son[i]->fail = x;
                else
                    p->son[i] = x;
            }
        }
    }
    int size() { return sz; }
} ac;
struct Matrix {
    double xx[M][M];
    Matrix(double x = 0) {
        memset(xx, 0, sizeof xx);
        for(int i = 1; i <= limit; i++) xx[i][i] = x;
    }
    double* operator [] (int x) { return xx[x]; }
    friend Matrix operator *(Matrix x, Matrix y) {
        Matrix z; int i, j, k;
        FOR(i,1,limit) FOR(j,1,limit) FOR(k,1,limit)
            z[i][j]+=x[i][k]*y[k][j];
        return z;
    }
} f;
int main() {
    string s;
    int i, j, p, q;
    scanf("%d%d%d", &n, &l, &m);
    FOR(i,1,m) scanf("%d%d", &p, &q), possibility[i] = (double)p/q;
    FOR(i,1,n-1) {
        cin>>s; ac.insert(s.c_str());
    }
    ac.build();
    limit = ac.size();

    FOR(i,1,limit) {
        printf("%d\n", ac.node[i].son[j]->id);
        if (ac.node[i].end)
            f[i][i] = 1;
        else
            FOR(j,1,m) {
                f[i][ac.node[i].son[j]->id] += possibility[j];
            }
    }
    FOR(i,1,50) f = f * f;
    FOR(i,1,n) printf("%.2lf\n",f[1][pos[i]]);
    return 0;
}
/**
3 2 2
1 2
1 2
AB
BA
AA
*/