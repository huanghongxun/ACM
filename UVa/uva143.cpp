#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point {
    double x, y;
};

double area(Point p1, Point p2, Point p3) {
    return fabs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
}

int main() {
    Point p1, p2, p3, p0;
    while (scanf("%lf %lf %lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y) == 6) {
        if (p1.x == 0 && p1.y == 0 && p2.x == 0 && p2.y == 0 && p3.x == 0 && p3.y == 0)
            break;
        int ans = 0;
        double i, j;
        
        int minX = max(1., ceil(min(p1.x, min(p2.x, p3.x))));
        int maxX = min(99., max(p1.x, max(p2.x, p3.x)));
        int minY = max(1., ceil(min(p1.y, min(p2.y, p3.y))));
        int maxY = min(99., max(p1.y, max(p2.y, p3.y)));
        
        double totalArea = area(p1, p2, p3);
        for (p0.x = minX; p0.x <= maxX; p0.x++)
            for (p0.y = minY; p0.y <= maxY; p0.y++)
                if (fabs(totalArea - (area(p0, p1, p2) + area(p0, p2, p3) + area(p0, p3, p1))) < 1e-9)
                    ans++;
        
        printf("%4d\n", ans);
    }
    return 0;
}