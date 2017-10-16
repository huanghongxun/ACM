#include <iostream>
#include <vector>
#include <map>
#include <string>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;

int main() {
    int T = 0, n, i, j, money, people;
    string name;
    while (cin >> n) {
        map<string, int> balance;
        vector<string> names;
        rep(i,0,n) {
            cin >> name;
            balance[name] = 0;
            names.push_back(name);
        }
        rep(i,0,n) {
            cin >> name;
            cin >> money >> people;
            if (people == 0)
                continue;
            int gift = money / people;
            balance[name] -= gift * people;
            rep(j,0,people) {
                cin >> name;
                balance[name] += gift;
            }
        }
        if (++T > 1)
            cout << endl;
        rep(i,0,n)
            cout << names[i] << " " << balance[names[i]] << endl;
    }
    return 0;
}