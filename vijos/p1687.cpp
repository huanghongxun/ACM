#include <iostream>
#include <cstring>
#include <algorithm>
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::reverse;
using std::max;
const int power = 1; //每次运算的位数为10的power次方，在这里定义为了方便程序实现
const int base = 10; //10的power次方。//要压位的时候，只需改power 和 base即可，如压万位高精，那么power = 4, base = 10000
#define MAXL 1001 //数组的长度。
char a[MAXL], b[MAXL];
struct num {
    int a[MAXL];
    num() {
        memset(a, 0, sizeof(a));
    }
    //初始化
    num(char *s) //将一个字符串初始化为高精度数
    {
        memset(a, 0, sizeof(a));
        int len = strlen(s);
        a[0] = (len+power-1) / power; //数的长度
        for(int i = 0, t = 0, w; i < len; w *= 10, ++i) {
            if(i % power == 0) { w = 1, ++t; }
            a[t] += w * (s[i]-'0');
        } //初始化数组，这里自己模拟一下，应该很容易懂的~
    }
    num(int r) {
        for(a[0] = 0; r > 0; r /= base)
            a[++a[0]] = r % base;
    }
    friend ostream & operator << (ostream &o, num &n) {
        o<<n.a[n.a[0]];
        for(int i = n.a[0]-1;i > 0;--i) {
            o.width(power);
            //o<<("%0*d", power, a[i]);
            o<<n.a[i];
        }
        return o;
    }
    friend istream & operator >> (istream &i, num &n) {
        char c[MAXL]; i>>c;
        reverse(c, c+strlen(c));
        n = num(c);
        return i;
    }
};
num operator + (const num &p, const num &q) //加法，不用多说了吧，模拟一遍，很容易懂
{
    num c; c.a[0] = max(p.a[0], q.a[0]);
    for(int i = 1;i <= c.a[0];++i) {
        c.a[i] += p.a[i] + q.a[i];
        c.a[i+1] += c.a[i] / base;
        c.a[i] %= base;
    }
    if(c.a[ c.a[0]+1]) ++c.a[0]; return c;
}
num operator - (const num &p, const num &q) //减法，也不用多说，模拟一遍，很容易懂
{
    num c = p;
    for(int i = 1;i <= c.a[0];++i) {
        c.a[i] -= q.a[i];
        if(c.a[i] < 0) {
            c.a[i] += base; --c.a[i+1];
        }
    }
    while(c.a[0] > 0&& !c.a[ c.a[0] ]) --c.a[0];
    //我的习惯是如果该数为0，那么他的长度也是0，方便比较大小和在末尾添加数时的判断。
    return c;
}
/*num operator * (const num &p, const num &q) //乘法，还是模拟一遍。。其实高精度就是模拟人工四则运算！
{
    num c; c.a[0] = p.a[0]+q.a[0]-1;
    for(int i = 1;i <= p.a[0];++i)
        for(int j = 1;j <= q.a[0];++j) {
            c.a[i+j-1] += p.a[i]*q.a[j];
            c.a[i+j] += c.a[i+j-1] / base;
            c.a[i+j-1] %= base;
        }
    if(c.a[ c.a[0]+1]) ++c.a[0];
    return c;
}*/
num operator * (const num &p, const int &q) {
    num c; int i;
    for(i = 1; i <= p.a[0]; i++) {
        c.a[i] = p.a[i] * q;
        c.a[i+1] = c.a[i] / base;
        c.a[i] %= base;
    }
    for(; c.a[i] != 0; i++) {
        c.a[i+1] = c.a[i] / base;
        c.a[i] %= base;
    }
    c.a[0] = i - 1;
    return c;
}
num f[1001];
int main() {
    int n;
    num k(500);k=k*500;
    cout<<k;
    cin>>n;
    f[n] = 1;
    for(int i=n-1;i>=2;i--)
        f[i]=f[i+1]*(i+1);
    num ans;
    for(int i = 2; i <= n; i++) {
        if(i&1) ans = ans - f[i];
        else ans = ans + f[i];
    }
    cout<<ans;
    return 0;
}