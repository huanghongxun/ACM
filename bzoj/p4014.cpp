/*#include <cstdio>
#define FOR(i,j,k) for(i=j;i<=k;i++)
const int N = 1000001;
const double pi = 3.1415926536;
int sx, sy, sx2, sy2, sxy, n;
int x[N], y[N];
double dis(double k, double b) {
    return (k*k*sx2+sy2+b*b*n-2*k*sxy-2*b*sy+2*b*k*sx)/(k*k+1);
}
double calc(double k) {
    double l=-1e9,r=-l;int i;
    FOR(i,1,100) {
        double l1 = (r - l) / 3 + l, r1 = (r - l) / 3 * 2 + l;
        double t1 = dis(k,l1), t2 = dis(k,r1);
        if (t1 > t2) l = l1; else r = r1;
    }
    return dis(k,l);
}
int main() {
    int t, a, b, c, i, kase; scanf("%d", &t);
    FOR(kase,1,t) {
        scanf("%d%d%d%d%d%d", &n, x+1, y+1, &a, &b, &c);
        sx = x[1]; sy = y[1]; sx2 = sx * sx; sy2 = sy * sy; sxy = sx * sy;
        FOR(i,2,n) x[i]=(a*x[i-1]*x[i-1]+b*x[i-1]+c)%107,
            y[i]=(a*y[i-1]*y[i-1]+b*y[i-1]+c)%107,
            sx+=x[i],sy+=y[i],sx2+=x[i]*x[i],sy2+=y[i]*y[i],sxy+=x[i]*y[i];
        double l=-1e9,r=-l;
        FOR(i,1,100) {
            double l1 = (r - l) / 3 + l, r1 = (r - l) / 3 * 2 + l;
            double t1 = calc(l1), t2 = calc(r1);
            if (t1 > t2) l = l1; else r = r1;
        }
        printf("Case %d: %.5lf\n", kase, calc(l)*pi/n);
    }
    return 0;
}*/
#include <cstdio>
#include <cmath>
int t,n,x,y,a,b,c,i,ii;
double ans,tmp,A,B,C,sx,sx2,sy,sy2,sxy,pi=acos(-1);
int main()
{
    for(scanf("%d",&t),ii=1;ii<=t;printf("Case %d: %.8lf\n",ii,ans*pi/n),ii++)
    {
        scanf("%d%d%d%d%d%d",&n,&x,&y,&a,&b,&c);
        sx=x,sy=y,sx2=x*x,sy2=y*y,sxy=x*y;
        for(i=2;i<=n;i++)
        {
            x=(a*x*x+b*x+c)%107;
            y=(a*y*y+b*y+c)%107;
            sx+=x,sy+=y,sx2+=x*x,sy2+=y*y,sxy+=x*y;
        }
        if(fabs(sx*sy/n-sxy)<=1e-10)ans=0;
        else
        {
            C=(sy2-sx2+(sx*sx-sy*sy)/n)/(sx*sy/n-sxy);
            B=(-C+sqrt(C*C+4))/2;
            A=(sy-B*sx)/n;
            ans=(sy2+n*A*A+B*B*sx2-2*A*sy-2*B*sxy+2*A*B*sx)/(1+B*B);
            B=(-C-sqrt(C*C+4))/2;
            A=(sy-B*sx)/n;
            tmp=(sy2+n*A*A+B*B*sx2-2*A*sy-2*B*sxy+2*A*B*sx)/(1+B*B);
            if(ans>tmp)ans=tmp;
        }
    }
}