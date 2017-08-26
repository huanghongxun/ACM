#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAXN 10
ll mi;
ll multi(ll a,ll b,ll n){
    ll temp=a%n,s=0LL;
    while(b){
       if(b&1LL)s=(s+temp)%n;
       temp=(temp+temp)%n;
       b>>=1;
    }
    return s;
}
ll Pow(ll a,ll b,ll n){
    ll temp=a%n,s=1LL;
    while(b){
       if(b&1LL)s=multi(s,temp,n);
       temp=multi(temp,temp,n);
       b>>=1;
    }
    return s;
}
ll Pow2(ll a,ll b){
    ll s = 1LL;
    for(int i = 0; i < b; ++i)
        s *= a;
    return s;
}
int witness(ll a,ll n){
    ll u=n-1LL,t=0LL,i,x,y;
    while(!(u&1LL))u>>=1,t++;
    x=Pow(a,u,n);
    for(i=1;i<=t;i++){
        y=multi(x,x,n);
        if(y==1LL&&x!=1LL&&x!=n-1LL)return 1;
        x=y;
    }
    if(x!=1LL)return 1;
    return 0;
}
int test(ll n){
    ll a;
    int i;
    if(n==2LL)return 1;
    if(n<2LL||!(n&1ll))return 0;
    for(i=0;i<MAXN;i++){
       a=(ll)rand()%(n-2)+2;
       if(witness(a,n))return 0;
    }
    return 1;
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll pollard_rho(ll n,ll c){
    ll x,y,d,i=1LL,k=2LL;
    x=((ll)rand())%(n-1LL)+1LL;
    y=x;
    while(1){
        ++i;
        x=(multi(x,x,n)+c)%n;
        d=gcd(y-x+n,n);
        if(d!=1&&d!=n)return d;
        if(x==y)return n;
        if(i==k){
                 y=x;
                 k<<=1;
        }
    }
}
void find(ll n,ll c = 70ll){
     ll r;
     if(n<=1LL) return ;
     if(test(n)){
       if(mi>n)mi=n;
       return ;
     }
     r=pollard_rho(n,c--);
     find(n/r,c);
     find(r,c);
}

ll top;
ll vec[1000000][2];
ll pri[] = {2,3,5,7,11,13,17,19,23,29};
int main()
{
    ll n,ans,cnt;
    int t,i;
    scanf("%d",&t);

    while(t--){
        top  = 0;
       scanf("%lld",&n);
       //vec.clear();
       for(i = 0; i < 10; ++i)
       {
           cnt = 0;
           while(n % pri[i] == 0)
           {
               ++cnt;
               n /= pri[i];
           }
           if(cnt)
                vec[top][0] = pri[i],vec[top++][1] = cnt;
       }
       while(n!=1){

           mi=n;
           find(n);
           cnt =0;
           while(n % mi == 0)
           {
               ++cnt;
               n /= mi;
           }
           vec[top][0] = mi,vec[top++][1] = cnt;
       }
       ans = 0;
       if(top == 1)
          vec[0][1] --;
        for(i = 0; i < top; ++i)
            ans += Pow2(vec[i][0],vec[i][1]);
       printf("%lld %lld\n",top,ans);
    }
    return 0;
}
