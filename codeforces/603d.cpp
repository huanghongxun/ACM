#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll gcd(ll x, ll y){
  for( ; y > 0; swap(x, y)) x %= y;
  return x;
}

pll reduce(ll x, ll y){
  ll g = gcd(abs(x), abs(y));
  if(g != 0) x /= g, y /= g;
  if((y < 0) || (y == 0 && x < 0)) x = -x, y = -y;
  return make_pair(x, y);
}

const int MAXN = 2005;
int N, A, B, C;
ll X[MAXN], Y[MAXN], Z[MAXN], res;

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A >> B >> C;
    X[i] = A * C;
    Y[i] = B * C;
    Z[i] = A * A + B * B;
  }
  for(int i = 0; i < N; i++){
    int tot = 0, zero = 0;
    map<pll,int> freq;
    for(int j = i+1; j < N; j++){
      ll u = X[i] * Z[j] - X[j] * Z[i];
      ll v = Y[i] * Z[j] - Y[j] * Z[i];
      pll p = reduce(u, v);
      if(p == pll()){
        res += tot;
        zero += 1;
      } else {
        res += freq[p] + zero;
        freq[p] += 1;
      }
      tot += 1;
    }
  }
  cout << res << '\n';
}