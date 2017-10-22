// HDU 3780, UVALive 4889
#include <cstdio>
#include <algorithm>
using namespace std;

int main () {
    double dim[3];
    while (scanf("%lf%lf%lf", dim + 0, dim + 1, dim + 2) == 3 && dim[0] + dim[1] + dim[2] != 0.0) {
        sort(dim, dim + 3);
        double length = dim[2], height = dim[1], thickness = dim[0];
        if (length >= 125 && height >= 90 && thickness >= 0.25) {
            if (length <= 290 && height <= 155 && thickness <= 7)
                puts("letter");
            else if (length <= 380 && height <= 300 && thickness <= 50)
                puts("packet");
            else if (length + height + height + thickness + thickness <= 2100)
                puts("parcel");
            else
                puts("not mailable");
        } else
            puts("not mailable");

    }
    return 0;
}