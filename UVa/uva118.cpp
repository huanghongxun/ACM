#include <cstring>
#include <algorithm>
#include <iostream>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;
bool block[1000][1000];
const int dx[] = { 0 , 1 , 0 ,-1 };
const int dy[] = { 1 , 0 ,-1 , 0 };
const char d[] = {'N','E','S','W'}; 

int main() {
    int n, m, dir, nx, ny, x, y, i;
    char ch;
    string str;

    cin >> n >> m;
    while (cin >> x >> y >> ch >> str) {
        rep(i,0,4) if (d[i] == ch) dir = i;
        int len = str.length();
        bool flag = true;
        rep(i,0,len) {
            if (str[i] == 'L')
                dir = (dir + 3) % 4;
            else if(str[i] == 'R')
                dir = (dir + 1) % 4;
            else if(str[i] == 'F') {
                nx = x + dx[dir];
                ny = y + dy[dir];
                if (nx < 0 || nx > n || ny < 0 || ny > m) {
                    if (block[x][y])
                        continue;
                    else {
                        block[x][y] = 1;
                        flag = false;
                        break;
                    }
                }
                x = nx; y = ny;
            }
        }
        cout << x << " " << y << " " << d[dir];
        if (!flag) cout << " LOST";
        cout << endl;
    }
} 