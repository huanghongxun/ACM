#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i,m,n) for(int i=m; i<n; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define mp make_pair
#define pb push_back
#define ri(a) scanf("%d",&a)
#define rii(a,b) scanf("%d%d",&a,&b)

typedef long long ll;
typedef vector<int> vi;
const int MAXN=100001;
const int MOD=1000000007;
int criba[MAXN]={};

ll sq(ll a){return a*a;}
ll modExp(ll a, ll e){return e? sq(modExp(a, e>>1))%MOD*((e&1) ? a : 1)%MOD: 1;}

void fillCriba(){
    for(int j=4; j<MAXN; j+=2) criba[j]=2;
    for(int i=3; i*i<MAXN; i+=2) if(!criba[i])
        for(int j=i*i; j<MAXN; j+=2*i) criba[j]=i;
}

vi factorizar(int n){
    vi f;
    for(; criba[n]; n/=criba[n]) f.pb(criba[n]);
    f.pb(n);
    return f;
}

vi factores(vi f){
    sort(f.begin(), f.end());
    f.resize(distance(f.begin(), unique(f.begin(), f.end())));
    return f;
}

ll fact[MAXN];
ll factInv[MAXN];

void fillFact(){
    fact[0]=factInv[0]=1;
    FOR(i, 1, MAXN) fact[i]=(fact[i-1]*i)%MOD;
    FOR(i, 1, MAXN) factInv[i]=modExp(fact[i], MOD-2);
}

ll c(int n, int m){
    if(m>n) return 0;
    ll res=;
    res = (fact[n]*factInv[m])%MOD*factInv[n-m]%MOD;
    return res;
}

int main(){
    fillCriba();
    fillFact();
    int q, n, f;
    ri(q);
    while(q--){
        rii(n, f);
        if(n==1){
            printf("%d\n", f==1);
            continue;
        }
        ll res=0;
        vi p=factores(factorizar(n));
        int k=p.size();
        FOR(j, 0, 1<<k){
            int s=1; int d=1;
            for(int i=0; i<k; i++) if((j>>i)&1){
                s=-s;
                d*=p[i];
            }
            res = (res+s*c(n/d-1, f-1)+MOD)%MOD;
        }
        printf("%I64d\n", res);
    }
}