#include <iostream>
#include <string>
#define N 5000005
using namespace std;

char stack[N];
int top = 0;
int maxend, end;
int maxlen = 0, nowlen = 0;

bool isLeft(char c) {
	return c == '{' || c == '[' || c == '(';
}

bool match(char a, char b) {
	return (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')');
}

void printStack() {
				for(int i = 1; i <= top; i++)
					cout<<stack[i]<<' ';
				cout<<endl;
}

int main() {
	string str;
	getline(cin, str);
	int len = str.length();
	for(int i = 0; i < len; i++) {
		if(isLeft(str[i])) {
			stack[++top] = str[i];
		} else {
			char c;
			if(top > 0 && match(c = stack[top], str[i])) {
				nowlen+=2;
				end = i;
				top--;
			} else {
				if(nowlen > maxlen) {
					maxlen = nowlen;
					maxend = end;
				}
				nowlen = 0;
			}
		}
	}
				if(nowlen > maxlen) {
					maxlen = nowlen;
					maxend = end;
				}
				nowlen = 0;
	for(int i = maxlen - 1; i >= 0; i--)
		cout<<str[maxend - i];

	return 0;
}