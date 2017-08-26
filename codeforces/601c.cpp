#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1005;

int n, m, x[N], s;
double p[N * M], tmp[N * M];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &x[i]);
    for(int i = 1; i <= n; ++i)
        s += x[i];
    if(m == 1)
    {
        puts("1.0000000000");
        return 0;
    }
    p[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        double now = 0;
        for(int j = 1; j < s; ++j)
        {
            now += p[j - 1];
            if(x[i] <= j)
                now -= p[j - x[i]];
            if(x[i] < j)
                now += p[j - x[i] - 1];
            if(m < j)
                now -= p[j - m - 1];
            tmp[j] = now / (m - 1);
        }
        for(int j = 0; j <= s; ++j) p[j] = tmp[j];
        copy(tmp, tmp + s, p);
    }   
    double ans = 0;
    for(int i = 1; i <= s; ++i)
        ans += p[i];
    ans = ans * (m - 1) + 1;
    printf("%.10f\n",ans);
    return 0;
}