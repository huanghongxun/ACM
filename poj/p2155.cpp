#include <cstdio>
#include <cstdlib>
#include <cstring>
bool b[2300][2300];
int T, N, Q, sum;

void update_y(int x, int y1, int y2)
{
    if(up == y2 && down == y1)
        b[rx][ry] = !b[rx][ry];
    else {
        int mid = (up + down) / 2;
        if(y2 <= mid) update_y(rx, ry * 2 , down, mid, y1, y2);
        else if(y1 > mid) update_y(rx, ry * 2 + 1, mid + 1, up, y1,  y2);
        else {
            update_y(rx, ry * 2 , down, mid, y1, mid);
            update_y(rx, ry * 2 + 1, mid + 1, up, mid + 1, y2);
        }
    }
}

void update_x(int x1, int x2, int y1, int y2)
{
    if(left == x1 && right == x2)
      update_y(r, 1, 1, N, y1, y2);
    else {
        int mid = (left + right) / 2;
        if(x2 <= mid) update_x(r * 2, left, mid, x1 , x2, y1, y2);
        else if(x1 > mid) update_x(r * 2 + 1, mid + 1, right, x1, x2, y1, y2);
        else {
            update_x(r * 2, left, mid, x1, mid, y1, y2 );
            update_x(r * 2 + 1, mid + 1, right, mid + 1, x2, y1, y2);
        }
    }
}

void query_y(int rx, int ry, int down, int up, int y)
{
    sum ^= b[rx][ry];
    if(down == up) return;
    int mid = (down + up) / 2;
    if(y <= mid) query_y(rx, ry * 2, down, mid, y);
    else query_y(rx, ry * 2 + 1, mid + 1, up, y);
}

void query_x(int r ,int left, int right, int x, int y)
{
    query_y(r, 1, 1, N, y);
    if(left == right) return;
    int mid = (left + right) / 2;
    if(x <= mid) query_x(r * 2, left, mid, x, y);
    else query_x(r * 2 + 1, mid + 1, right, x, y);
}

int main()
{
    char tmp[20];
    int x1, x2, y1, y2;
    scanf("%d", &T);
    while(T--) {
        memset(b, 0, sizeof(b));
        scanf("%d%d", &N, &Q);
        while(Q--) {
            scanf("%s %d %d", tmp, &x1, &y1);
            if(tmp[0] == 'C') {
                scanf("%d %d", &x2, &y2);
                update_x(1, 1, N, x1, x2, y1, y2);
            }
            else if(tmp[0] == 'Q') {
                sum = 0;
                query_x(1, 1, N, x1, y1);
                printf("%d\n", sum);
            }
        }
        putchar('\n');
    }
    return 0;
}