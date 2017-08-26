#include <cstdio>
#include <string>
#include <algorithm>
#define N 100000
#define M 100000
using namespace std;

int size = 0;
char ch;
string str = "";

int main() {

	while(~scanf("%c", &ch)) {
		str += ch;
		int len = str.length();
		if(len > 5) {
			if(str[len - 5] == 'b' && str[len - 4] == 'e' && str[len - 3] == 'g' && str[len - 2] == 'i' && str[len - 1] == 'n') {
				break;
			}
		}
		if(ch == ',')
			size++;
		if(ch == ':')
			size++;
	}
	printf("%d", size);
	return 0;
}