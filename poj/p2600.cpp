// POJ 2600, URAL 1046
#include <cstdio>
#include <complex>
#include <cmath>
#define FOR(i,j,k) for(i=j;i<=k;++i)
using namespace std;

const int N=55;
const double PI=acos(-1.0);

template<typename T>
complex<T> comp(T a, T b) {
    return complex<T>(a, b);
}

int n;
complex<double> M[N],ans[N];
double a[N];

int main(){
  complex<double> x, y, tmp;

  scanf("%d",&n);
  double ix,iy;
  for (int i=1;i<=n;i++)
    scanf("%lf%lf",&ix,&iy),M[i]=comp(ix,iy);
  for (int i=1;i<=n;i++)
    scanf("%lf",&a[i]),a[i]=a[i]/180.0*PI;
  complex<double> x(1,0),y(0,0),tmp;
  for (int i=1;i<=n;i++){
    tmp = comp(cos(a[i]),sin(a[i]));
    x*=tmp;
    y-=M[i],y*=tmp,y+=M[i];
  }
  ans[1] = (-y) / (x - comp(1, 0));
  x = comp(1, 0); y = comp(0, 0);
  for (int i=1;i<=n;i++){
    tmp=comp(cos(a[i]),sin(a[i]));
    x*=tmp;
    y-=M[i],y*=tmp,y+=M[i];
    ans[i+1]=x*ans[1]+y;
  }
  for (int i=1;i<=n;i++)
    printf("%.2lf %.2lf\n",ans[i].real(),ans[i].imag());
  return 0;
}
