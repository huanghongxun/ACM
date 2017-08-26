#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;
const int INF = 0x7fffffff;

int n;

struct Point {
	double x,y;
	Point(double x=0, double y=0):x(x),y(y) {}
	bool operator < (const Point& p) const {
		if(x != p.x) return x < p.x;
		else return y < p.y;
	}
} p[200005],temp[200005];

inline bool cmpy(const Point &a, const Point &b) {
	return a.y<b.y;
}

inline double dis(Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double getClosest(int l, int r) {
	double d = INF;
	if(l == r)
		return d;
	if(l +1 == r)
		return dis(p[l],p[r]);
	int mid = (l+r)>>1;
	double d1 = getClosest(l,mid);
	double d2 = getClosest(mid,r);
	d = min(d1,d2);
	int k = 0;
	for(int i = l; i <= r; i++)
	{
		if(fabs(p[mid].x - p[i].x) <= d)
			temp[k++] = p[i];
	}
	sort(temp,temp+k,cmpy);
	for(int i = 0; i < k; i++) {
		for(int j = i+1; j < k && temp[j].y - temp[i].y < d; j++) {
			double d3 = dis(temp[i],temp[j]);
			d = min(d,d3);
		}
	}
	return d;
}


int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		double a,b;
		scanf("%lf%lf",&a,&b);
		p[i] = Point(a,b);
	}
	sort(p,p+n);
	printf("%.3f",getClosest(0,n-1));

	return 0;
}
