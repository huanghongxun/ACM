#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define rep(i,j,k) for(int i=j;i<k;i++)
typedef long long ll;
using namespace std;
const int mod = 65521;
ll n, A[64];
int pos[1<<15], tot, k;
struct Matrix {
    ll c[64][64];
    explicit Matrix(ll x = 0) {
        memset(c,0,sizeof(c));
        FOR(i,1,tot) c[i][i]=x;
    }
    ll *operator [](int x) { return c[x]; }
    friend Matrix operator *(Matrix a, Matrix b) {
        Matrix re;
        FOR(i,1,tot) FOR(j,1,tot) FOR(k,1,tot)
            re[i][j]=(re[i][j]+a[i][k]*b[k][j]) % mod;
        return re;
    }
    friend Matrix operator ^(Matrix a, ll k) {
        Matrix re(1);
        for(;k;a=a*a,k/=2)if(k&1)re=re*a;
        return re;
    }
} B;
void decompress(int a[], int sta) {
    rep(i,0,k) a[i]=(sta>>i*3)&7;
}
int compress(int a[]) {
    int re = 0;
    rep(i,0,k) re|=a[i]<<i*3;
    return re;
}
bool valid(int sta) {
    static int a[8];
    int now = 1;
    decompress(a,sta);
    rep(i,0,k)
        if (a[i] == 0 || a[i] > now)
            return false;
        else if (a[i] == now)
            ++now;
    return true;
}
void init_valid_status() {
    rep(i,0,1<<k*3)
        if (valid(i))
            pos[i]=++tot;
}
void Standardize(int a[]) {
    static int b[10];
    int i,cnt=0;
    memset(b,0,sizeof b);
    for(i=0;i<k;i++)
        if(!b[a[i]])
            b[a[i]]=++cnt;
    for(i=0;i<k;i++)
        a[i]=b[a[i]];
}
void Calculate1(int status) {
    static int a[8], b[8], cnt[8];
    int _sta,limit=0;
    decompress(a, status);
    memset(cnt, 0, sizeof cnt);
    rep(i,0,k) {
        cnt[a[i]]++;
        limit=max(limit,a[i]);
    }
    for(_sta=cnt[1]==1;_sta<1<<limit;_sta+=(cnt[1]==1)+1) {
        int temp=1;
        memcpy(b,a,sizeof b);
        b[k]=9;
        FOR(i,1,limit)
            if(_sta&(1<<i-1))
                temp*=cnt[i];
        rep(i,0,k)
            if(_sta&(1<<a[i]-1))
                b[i]=9;
        Standardize(b+1);
        ::a[ pos[status] ][ pos[compress(b+1)] ]=temp;
    }
}
void calc_A(ll A[], int status) {
    static int a[8], cnt[8];
    int re = 1;
    decompress(a, status);
    memset(cnt,0,sizeof cnt);
    rep(i,0,k) cnt[a[i]]++;
    for(int i=1;cnt[i];i++)
        re*=pow(cnt[i],cnt[i]-2);
    A[pos[status]]=re;
}
void init_matrix() {
    rep(i,0,1<<k*3)
        if(pos[i]) {
            Calculate1(i);
            calc_A(A, i);
        }
}
int main() {
    scanf("%d%lld", &k, &n);
    if(k > n) k = n;
    init_valid_status();
    init_matrix();
    Matrix res = B ^ (n - k);
    ll ans = 0;
    FOR(i,1,tot) ans = (ans + A[i] * res[i][1]) % mod;
    printf("%lld", ans);
    return 0;
}