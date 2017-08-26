#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;
typedef long long ll;
#define FOR(i,j,k) for(int i=j;i<=k;i++)
ll n, p;
struct Matrix {
    ll c[4][4];
    Matrix(ll x = 0) {
        memset(c,0,sizeof(c));
        FOR(i,1,3) c[i][i]=x;
    }
    ll *operator [](int x) { return c[x]; }
    friend Matrix operator *(Matrix a, Matrix b) {
        Matrix re;
        FOR(i,1,3) FOR(j,1,3) FOR(k,1,3)
            re[i][j]=(re[i][j]+a[i][k]*b[k][j])%p;
        return re;
    }
    friend Matrix operator ^(Matrix a, ll k) {
        Matrix re(1);
        for(;k;a=a*a,k/=2)if(k&1)re=re*a;
        return re;
    }
} ans(1);
Matrix create(int t) {
    Matrix x;
    x[1][1]=x[2][1]=x[2][2]=x[3][1]=x[3][2]=1;
    x[3][3]=t%p;
    return x;
}
int main() {
    ll i;
    scanf("%lld%lld", &n, &p);
    {
        printf("%lld", ((create(10)^8)*(create(100)^2))[3][1]);
        return 0;
    }
    for(i=100;i<=n;i*=10)  
        ans=ans*(create(i)^(i-i/10));
    ans=ans*(create(i)^(n-i/10+2));
    printf("%lld", ans[3][1]%p);
    return 0;
}  
