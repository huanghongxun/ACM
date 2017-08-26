#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int power = 5;
const int base = 100000;
#define MAXL 100005
struct num {
    int a[MAXL];
    num() {
        memset(a, 0, sizeof(a));
    }
    num(char *s)
    {
        memset(a, 0, sizeof(a));
        int len = strlen(s);
        a[0] = (len+power-1) / power;
        for(int i = 0, t = 0, w; i < len; w *= 10, ++i) {
            if(i % power == 0) { w = 1, ++t; }
            a[t] += w * (s[i]-'0');
        }
    }
    num(int r) {
        for(a[0] = 0; r > 0; r /= base)
            a[++a[0]] = r % base;
    }
    void add(int k) {
        if(k || a[0]) a[ ++a[0] ] = k;
    }
    void  re() { reverse(a+1, a+a[0]+1); }
    friend ostream & operator << (ostream &o, const num n) {
        o<<n.a[n.a[0]];
        for(int i = n.a[0]-1;i > 0;--i) {
            o.width(power);
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
} n, p, q, mid, l, r;
bool operator < (const num &p, const num &q)
{
    if(p.a[0] < q.a[0]) return true;
    if(p.a[0] > q.a[0]) return false;
    for(int i = p.a[0]; i > 0; --i) {
        if(p.a[i] != q.a[i]) return p.a[i] < q.a[i];
    }
    return false;
}
bool operator <= (const num &p, const num &q)
{
    if(p.a[0] < q.a[0]) return true;
    if(p.a[0] > q.a[0]) return false;
    for(int i = p.a[0];i > 0;--i) {
        if(p.a[i] != q.a[i]) return p.a[i] < q.a[i];
    }
    return true;
}
bool operator == (const num &p, const num &q)
{
    if(p.a[0] != q.a[0]) return false;
    for(int i = p.a[0];i > 0;--i) {
        if(p.a[i] != q.a[i]) return false;
    }
    return true;
}
num operator + (const num &p, const num &q)
{
    num c; c.a[0] = max(p.a[0], q.a[0]);
    for(int i = 1;i <= c.a[0];++i) {
        c.a[i] += p.a[i] + q.a[i];
        c.a[i+1] += c.a[i] / base;
        c.a[i] %= base;
    }
    if(c.a[ c.a[0]+1]) ++c.a[0]; return c;
}
num operator - (const num &p, const num &q)
{
    num c = p;
    for(int i = 1;i <= c.a[0];++i) {
        c.a[i] -= q.a[i];
        if(c.a[i] < 0) {
            c.a[i] += base; --c.a[i+1];
        }
    }
    while(c.a[0] > 0&& !c.a[ c.a[0] ]) --c.a[0];
    return c;
}
num operator * (const num &p, const num &q)
{
    num c; c.a[0] = p.a[0]+q.a[0]-1;
    for(int i = 1; i <= p.a[0]; i++)
        for(int j = 1; j <= q.a[0]; j++) {
            c.a[i+j-1] += p.a[i]*q.a[j];
            c.a[i+j] += c.a[i+j-1] / base;
            c.a[i+j-1] %= base;
        }
    if(c.a[ c.a[0]+1]) ++c.a[0];
    return c;
}
num operator * (const num &p, const int &q)
{
    num x = 0;
    if (p.a[0] <= 0 || !q) return x;
    int carry = 0, i;
    for (i = 1; i <= p.a[0] || carry; i++) {
        if (i <= p.a[0]) carry += p.a[i] * q;
        x.a[i] = carry % base;
        carry /= base;
    }
    x.a[0] = i-1;
    return x;
}
num operator / (const num &p, const num &q)
{
    num x, y;
    for(int i = p.a[0]; i >= 1; i--) {
        y.add(p.a[i]);
        y.re();
        while( !(y < q) )
            y = y - q, x.a[i]++;
        y.re();
    }
    x.a[0] = p.a[0];
    while(x.a[0] > 0 && !x.a[x.a[0]]) x.a[0]--;
    return x;
}
num operator / (const num &p, const int &q) {
	num x = p;
	int carry = 0;
	for (int i = x.a[0]; i >= 1; i--) {
		x.a[i] += carry * base;
		carry = x.a[i] % q;
		x.a[i] /= q;
	}
    while(x.a[0] > 0 && !x.a[x.a[0]]) x.a[0]--;
    return x;
}
const int N = 10005;
struct storage {
    int a, b, c;
    friend bool operator < (const storage &a, const storage &b) {
        return a.a == b.a ? a.b == b.b ? a.c < b.c : a.b < b.b : a.a < b.a;
    }
    friend bool operator > (const storage &a, const storage &b) {
        return a.a == b.a ? a.b == b.b ? a.c > b.c : a.b > b.b : a.a > b.a;
    }
    friend istream & operator >> (istream &i, storage &s) {
        i>>s.b>>s.c; s.a = s.b * s.c;
        return i;
    }
    friend ostream & operator << (ostream &i, storage &s) {
        i<<s.a<<' '<<s.b<<' '<<s.c;
        return i;
    }
} d[N];
void getmax(num &a, const num &b) {
    if(a < b) a = b;
}
int main() {
    int n, a, b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    sort(d+1,d+n+1);
    num to = a, ans = 0;
    //cout<<num(123)<<endl;
    for(int i=1;i<=n;i++) {
    	//cout<<d[i]<<endl;
        getmax(ans,to/d[i].c);
        to = to * d[i].b;
    }
    cout<<ans<<endl;
    return 0;
}
