#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define X first
#define Y second

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int N,M;
cin >> N >> M;
int COMP[N];
int SOCK[M];

//answers
int compus=0;
int B[N];memset(B,0,sizeof B);//number of socket connected to i computer
int P[M];memset(P,0,sizeof P);//number of adapters connected to i socket
int U=0;

unordered_map<int,vi > comp;
vector<pii> sck;
vector<pii>res;

res.reserve(M);
sck.reserve(M);

for(int i=0;i<N;i++){
  int C;
  cin >> C;
  COMP[i]=C;
  comp[C].push_back(i);
}
for(int i=0;i<M;i++){
  int S;cin >> S;
  SOCK[i]=S;
  sck.push_back({i+1,S});
}


int ad=0;
while(sck.size()){
  for(int i=0;i<sck.size();i++){
    int socketnumber=sck[i].X;
    int power=sck[i].Y;
    if(comp[power].size() ){
      int compu=comp[power].back();
      comp[power].pop_back();
      U+=ad;
      B[compu] =socketnumber;
      P[socketnumber-1]=ad;
      compus++;
    }else
    if(sck[i].Y>1){sck[i].Y=sck[i].Y/2+sck[i].Y%2;res.push_back(sck[i]);}
  }

  swap(res,sck);
  res.clear();
  ad++;
}
cout << compus <<" "<<U<<endl;

for(int i=0;i<M;i++)cout << P[i]<<" ";
cout << endl;
for(int i=0;i<N;i++)cout << B[i]<<" ";
cout << endl;

}