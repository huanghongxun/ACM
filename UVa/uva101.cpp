#include <cstdio>
#include <vector>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;
const int N = 105;
vector<int> piles[N];
int temp[N], temp_cnt = 0;
int pile[N], height[N];

template<class T>
void internal(int from, int h, T callback) {
    while (piles[from].size() >= h) {
        int x = *piles[from].rbegin();
        piles[from].pop_back();
        int pile_id = callback(x);
        piles[pile_id].push_back(x);
        height[x] = piles[pile_id].size();
        pile[x] = pile_id;
    }
}

void restoreBlocks(int from, int h) {
    internal(from, h, [](int x){ return x; });
}

void moveBlocks(int from, int h, int to) {
    internal(from, h, [=](int x){ return to; });
}

int main() {
    int n, from, to, i, t = 0;
    char op[8], prep[8];

    rep(i,0,n) pile[i] = i, height[i] = 1;

    while (scanf("%s%d%s%d", op, &from, prep, &to) == 4
            && op[0] != 'q') {

        if (prep[0] == 'o') // onto
            restoreBlocks(pile[to], height[to]);

        if (op[0] == 'm') // move
            restoreBlocks(pile[from], height[from]);

        moveBlocks(pile[from], height[from], pile[to]);

    }
    rep(i,0,n) {
        printf("%d:", i);
        for (auto element : piles[i])
            printf(" %d", element);
        printf("\n");
    }

    return 0;
}