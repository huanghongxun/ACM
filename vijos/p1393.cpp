#include <cstdio>
#include <cmath>
#define sqr(i) ((i)*(i))
int main() {
    double m,n,r;
    scanf("%lf%lf%lf", &m, &n, &r);
    if(m<=n) printf("%.3lf", r);
    else printf("%.3lf", sqrt(sqr(m-n)+sqr(r)));
    return 0;
}