#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <assert.h>

#define y1 aasdfasdfasdf

#define eps 1e-16
#define M_PI 3.141592653589793
const int N = 200005;
using namespace std;

long double x1,y1,x2,y2,r1,r2;

long double gd(long double x1,long double y1,long double x2,long double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

long double cut(long double d, long double r1, long double r2)
{
    long double angle = acos((r2*r2+d*d-r1*r1)/(2*r2*d))*2;
    long double sector = angle * r2 * r2 / 2;
    long double triangle = r2 * r2 * sin(angle) / 2;
    return sector - triangle;
}

long double solve()
{
    long double cd=gd(x1,y1,x2,y2);
    return cut(cd,r1,r2)+cut(cd,r2,r1);
}

int main()
{
    cin>>x1>>y1>>r1;
    cin>>x2>>y2>>r2;
    cout.precision(12);
    cout<<fixed<<(double)solve()<<endl;
    return 0;
}