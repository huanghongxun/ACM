#include <cstdio>
#include <cstring>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
const int M = 121, N = 21, mod = 45989;
int h[N], p[M], f[M], v[M], cnt = 0;
void add(int r, int s) {
    p[++cnt] = h[r]; h[r] = cnt; v[cnt] = s; f[cnt] = r;
}
struct Matrix {
    int v[M][M];
    Matrix(int x=0){memset(v,0,sizeof v);}
    int *operator[] (int x) { return v[x]; }
    friend Matrix operator *(Matrix a, Matrix b) {
        Matrix re;
        FOR(i,1,cnt)FOR(j,1,cnt)FOR(k,1,cnt)
            re[i][j]=(re[i][j]+a[i][k]*b[k][j])%mod;
        return re;
    }
    friend Matrix operator ^(Matrix a, int b) {
        Matrix re(1);
        FOR(i,1,cnt)re[i][i]=1;
        for(;b;b/=2,a=a*a)if(b&1)re=re*a;
        return re;
    }
} a, b;

int main() {
    int r, s, ans = 0, A, B, n, m, t;
    scanf("%d%d%d%d%d", &n, &m, &t, &A, &B);
    FOR(i,1,m) { scanf("%d%d", &r, &s); add(r, s); }
    for(int i=h[A];i;i=p[i])a[1][i]++;
    FOR(i,2,cnt)FOR(j,2,cnt) if(v[i]==f[j]&&i!=(j^1))b[i][j]++;
    a=a*(b^(t-1));
    for(int i=h[B];i;i=p[i])ans+=a[1][i^1];
    printf("%d", ans);
    return 0;
}