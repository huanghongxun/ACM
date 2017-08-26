#include <iostream>
using namespace std;

bool f[30000];
int d[30000];
int v[200],ss,st,i,j,k,n;
double a[200],sum;
void print(int x)
{
     if (x==0) return;
     print(x-v[d[x]]);
     if (x!=k) cout << d[x] << " ";
     else cout << d[x] << endl;
}
int main()
{
    freopen("pin.txt","r",stdin);
    freopen("pou.txt","w",stdout);
    while (scanf("%d",&n)!=EOF)
    {
          if (n==0) break;
          sum=0;
          for (i=1;i<=n;i++)
          {
              cin >> a[i];
              sum+=a[i];
          }
          ss=0;
          for (i=1;i<=n;i++)
          {
              v[i]=int(a[i]*20000.0/sum);
              ss+=v[i];
          }
          st=int(ss);
          memset(f,0,sizeof(f));
          f[0]=true;
          for (i=1;i<=n;i++)
              for (j=st;j>=v[i];j--)
                  if (f[j-v[i]] && !f[j])
                  {
                     f[j]=true;
                     d[j]=i;
                  }
          int ans=99999999;
          for (i=st;i;i--)
              if (f[i] && abs(ss-2*i)<ans)
                 ans=abs(ss-2*i),k=i;
          print(k);
    }
    return 0;
}