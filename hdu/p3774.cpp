#include <cstdio>

int climbers(int rope, int total, int max) {
    if (total * 2 > rope) return 0;
    return rope / max + 1; // for the first climber.
}

int main() {
    int pitch, n, total, max;
    while (scanf("%d", &n) == 1 && n != 0) {
        total = max = 0;
        while (n--) {
            scanf("%d", &pitch);
            total += pitch;
            if (pitch > max) max = pitch;
        }
        printf("%d %d %d\n",
            climbers(50, total, max),
            climbers(60, total, max),
            climbers(70, total, max));
    }

    return 0;
}