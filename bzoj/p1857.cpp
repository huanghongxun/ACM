#include <cstdio>
#include <cmath>
const double eps = 1e-4;

struct Point {
	double x, y;
	
	Point operator + (const Point& a) { return (Point) {x+a.x, y+a.y}; }
	Point operator - (const Point& a) { return (Point) {x-a.x, y-a.y}; }
	Point operator * (const double& a) { return (Point) {x*a, y*a}; }
	Point operator / (const double& a) { return (Point) {x/a, y/a}; }
	
	void read() { scanf("%lf%lf", &x, &y); }
	
} A, B, C, D;

double p, q, r;

inline double dis(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline double dis2(Point a, Point b) {
	return dis(A, a) / p + dis(a, b) / r + dis(b, D) / q;
}

double calc(Point p0) {
	Point l = C, r = D;
	while (dis(l, r) > eps) {
		Point delta = (r - l) / 3;
		Point l2 = l + delta, r2 = l2 + delta;
		double ret1 = dis2(p0, l2), ret2 = dis2(p0, r2);
		if (ret1 < ret2) r = r2; else l = l2;
	}
	return dis2(p0, l);
}

int main() {
	A.read(); B.read(); C.read(); D.read();
	scanf("%lf%lf%lf", &p, &q, &r);
	
	Point l = A, r = B;
	while (dis(l, r) > eps) {
		Point delta = (r - l) / 3;
		Point l2 = l + delta, r2 = l2 + delta;
		double ret1 = calc(l2), ret2 = calc(r2);
		if (ret1 < ret2) r = r2; else l = l2;
	}
	printf("%.2lf\n", calc(l));
	
	return 0;
}