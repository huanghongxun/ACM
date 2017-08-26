#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100 * 1000 + 10;

long long a[MAX_N], b[MAX_N], c[MAX_N];
long long n, m, g;

bool k(long long x)
{
    long long j = n - 1, tedad = 0, z = 0;
    for(int i = x - 1; i >= 0; i--)
    {
        if(b[i] <= a[j])
            tedad = tedad + 1;
        else if(b[i] <= a[j] + g)
        {
            z = z + (b[i] - a[j]);
            tedad = tedad + 1;
        }
        j = j - 1;
    }
    if(tedad == x && z <= g)
        return true;
    else
        return false;
}
int bai(long long start , long long end)
{
    if(start + 1 == end)
        return start;
    long long m = (start + end) / 2;
    if(k(m) == true)
        return bai(m , end);
    else
        return bai(start , m);
}
int main()
{
    long long x, j , sum = 0, z = 0;
    cin >> n >> m >> g;
    j = n - 1;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a , a + n);
    sort(b , b + m);
    x = bai(0 , (min(n , m)) + 1);
    for(int i = x - 1; i >= 0; i--)
    {
        if(a[j] >= b[i])
            sum = sum + b[i];
        else
        {
            sum = sum + a[j];
            z = z + (b[i] - a[j]);
        }
        j = j - 1;
    }
    g = g - z;
    if(g >= 0 && g >= sum)
        cout << x << " " << 0 << endl;
    else if(g >= 0 && g < sum)
        cout << x << " " << sum - g << endl;
    else if(g < 0)
        cout << 0 << " " << 0 << endl;
    return 0;
}       
    