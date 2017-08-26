#include <iostream>
#include <string>
#include <cstring>
using namespace std;
long a[6005];
string s;

void solve() {
	long i, j;
	memset(a, 0, sizeof(a));
	a[0] = 1;
	for(i = 0; i < s.length(); i++) {
		if(s[i] == '0') {
			a[i + 1] = a[i - 1];
			continue;
		}
		if(s[i] == '1' || s[i] == '2' && s[i + 1] <= '6') {
			a[i + 1] = a[i] + a[i - 1];
			continue;
		}
		a[i + 1] = a[i];
	}
	cout<<a[s.length()]<<endl;
}

int main() {
	getline(cin, s);
	while(s != "0") {
		solve();
		getline(cin, s);
	}
	return 0;
}