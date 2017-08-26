#include <cstdio>
#define ll long long 
ll gcd(ll a,ll b)
{ return b==0?a:gcd(b,a%b); }
void exgcd(ll a,ll b,ll &x,ll &y) {
    if(b==0){x=1;y=0;return;}
    exgcd(b,a%b,x,y);
    ll t=x;x=y;y=t-a/b*y;
}
int main() {
    ll A,B,C,k;
    ll x,y,a,b,c,t;
    while(scanf("%lld%lld%lld%lld",&A,&B,&C,&k))
    {
        if(!A&&!B&&!C&&!k)return 0;
        a=C;b=1ll<<k;c=B-A;
        t=gcd(a,b);
        if(c%t!=0){printf("FOREVER\n");continue;}
        exgcd(a,b,x,y);
        x=((c/t*x)%b+b)%b;
        if(x<0)x+=b;
        printf("%lld\n",x);
    }
}