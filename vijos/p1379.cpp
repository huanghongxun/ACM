#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int p1, p2, p3;
string str, ans;
int main() {
	cin >> p1 >> p2 >> p3 >> str;
	ans += *str.begin();
	for (int i=1; i<str.size()-1; ++i) {
		if (str[i] != '-' || str[i-1] == '-' || (str[i-1] >= str[i+1]) || !((isdigit(str[i-1]) == isdigit(str[i+1])) || (isalpha(str[i-1]) == isalpha(str[i+1])))) {
			ans += str[i];
			continue;
		}
		for (char p=str[i-1]+1; p<str[i+1]; ++p)
			if (p1 == 1)
				ans += string(p2, tolower(p));
			else if (p1 == 2)
				ans += string(p2, toupper(p));
			else
				ans += string(p2, '*');
		if (p3 == 2) reverse(ans.end()-p2*(str[i+1]-1-str[i-1]), ans.end());
	}
	cout << ans << *(str.end()-1);
	return 0;
}