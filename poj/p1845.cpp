/*#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll maxn=50000005;
const ll mod = 9901;
ll factor[100];
ll num[50000005];
ll cnt;
void getfactor(ll A,ll B){
    cnt=0;
    for(ll i=2;i*i<=A;i++){
        int count=0;
        if(A%i!=0)continue;
        while(A%i==0){
            A/=i;
            count++;
        }
        num[cnt]=count*B;
        factor[cnt++]=i;
    }
    if(A!=1){
        num[cnt]=B;
        factor[cnt++]=A;
    }
}
ll mul(ll a, ll b){
    ll ans = 0;
    for (; b; a = a * 2 % mod, b /= 2)
        if (b & 1) ans = (ans + a) % mod;
    return ans;
}
ll pow(ll a, ll b){
    ll ans = 1;
    for (; b; b /= 2, a = mul(a, a))
        if(b & 1) ans = mul(ans, a);
    return ans;
}
ll solve(ll p,ll n){
    return (pow(p,n+1,(p-1)*mod)-1)/(p-1);
}
int main() {
    ll A,B;
    while(scanf("%I64d%I64d",&A,&B)!=EOF){
        getfactor(A,B);
        ll ans=1;
        for(ll i=0;i<cnt;i++){
            ans=mul(ans,solve(factor[i],num[i]));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}*/ #include <iostream>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll maxn=50000005;
ll factor[100];
ll num[maxn];
ll cnt;
void getfactor(ll A,ll B){
    cnt=0;
    for(ll i=2;i*i<=A;i++){
        int count=0;
        if(A%i!=0)continue;
        while(A%i==0){
            A/=i;
            count++;
        }
        num[cnt]=count*B;
        factor[cnt++]=i;
    }
    if(A!=1){
        num[cnt]=B;
        factor[cnt++]=A;
    }
}
ll mul(ll a,ll b,ll mod){
    ll res=0;
    for(;b;b/=2,a=a*a%mod)
        if(b&1)res=(res+a)%mod;
    return res;
}
ll pow(ll a, ll b,ll c){
    ll res=1;
    for(;b;b/=2,a=mul(a,a,c))
        if(b&1)res=mul(res,a,c);
    return res;
}
ll sum(ll p,ll n){
    return (pow(p,n+1,(p-1)*9901)-1)/(p-1);
}
int main()
{
    ll A,B;
    while(scanf("%I64d%I64d",&A,&B)!=EOF){
        getfactor(A,B);
        ll res=1;
        for(ll i=0;i<cnt;i++){
            res=mul(res,sum(factor[i],num[i]),9901);
        }
        printf("%I64d\n",res);
    }
    return 0;
}