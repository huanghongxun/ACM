#include <iostream>
using namespace std;
#define N 32005
inline int lowbit(int t)
{
    return t&(-t);
}

inline int sum(int *c, int end)
{
    int s = 0;
    while(end > 0)
    {
        s += c[end];
        end -= lowbit(end);
    }
    return s;
}

inline int sum(int *c, int from, int to)
{
    return sum(c, to) - sum(c, from - 1);
}

inline int add(int *c, int pos, int num, int n)
{
    while(pos <= n)
    {
        c[pos] += num;
        pos += lowbit(pos);
    }
}

//树状数组的基类型一般是整型
//arr的元素从1开始
inline void create(int *arr, int *c, int n)
{
    for(int i=1; i<=n; i++)
        add(c, i, arr[i], n);
}

int main() {
    cin>>n;
    int x[N], y[N], cx[N], cy[N];
    for(i = 1; i <= n; i++)
        cin>>x[i]>>y[i];
    create(x, cx, n);
    create(y, cy, n)

    return 0;
}