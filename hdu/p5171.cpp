#include <cstdio>
#include <algorithm>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
typedef long long ll;
const ll mod = 10000007;
ll read() {
    ll s=0,f=1;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())s=s*10+ch-'0';
    return s*f;
}
struct Matrix {
    ll v[4][4];
    Matrix() { memset(v, 0, sizeof v); }
    Matrix(int x) : Matrix() { FOR(i,1,3) v[i][i]=x; }
    friend Matrix operator *(const Matrix &a, const Matrix &b) {
        Matrix re;
        FOR(i,1,3) FOR(j,1,3) FOR(k,1,3) re[i][j]=(re[i][j]+a[i][k]*b[k][j])%mod;
        return re;
    }
    friend Matrix operator ^(const Matrix &a, int b) {
        Matrix re(1);
        for(;b;b/=2,a=a*a)if(b&1)re=re*a;
        return re;
    }
    ll *operator [] (int x) { return v[x]; }
};
int main() {
    static ll s[100001];
    int n = read(), k = read(), sum = 0;
    FOR(i,1,n) s[i] = read(), sum = (sum + s[i]) % mod;
    std::sort(s + 1, s + 1 + n);
    if (s[n] <= 0) {
        printf("%lld", (sum+(s[n]+s[n-1])*k)%mod);
    } else {
        while (s[n-1]&&k) {
            s[n-1]=(s[n]+s[n-1])%mod;
            sum=(sum+s[n-1])%mod;
            k--;
        }
        Matrix a, b;
        b[1][2]=b[2][1]=b[2][2]=b[3][1]=b[3][2]=b[3][3]=1;
        a[1][1]=s[n-1];a[2][1]=s[n];a[3][1]=sum;
        printf("%lld", (((b^k)*a)[3][1]%mod+mod)%mod);
    }
    return 0;
}