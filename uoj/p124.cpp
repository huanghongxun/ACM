#include <cstdio>
#include <cstring>

typedef long long ll;

const int L = 1e6+5;
const int Mod = 1e9+7;

struct Matrix {
	int a, b;
	inline friend Matrix operator *(const Matrix &a, const Matrix &b) {
		return (Matrix) {(ll)a.a * b.a % Mod, ((ll)a.a * b.b + a.b) % Mod};
	}
	friend inline Matrix operator ^(const Matrix &a, const char *strN) {
		static Matrix matI = (Matrix) {1, 0};
		Matrix res = matI, t = a;

		for (int i = strlen(strN) - 1; i >= 0; i--) {
			Matrix powT = matI;
			for (int j = 1; j <= 10; j++) {
				powT = powT * t;
				if (j == strN[i] - '0')
					res = res * powT;
			}
			t = powT;
		}
		return res;
	}
};

inline void minusOne(char *strN) {
	int i = strlen(strN) - 1;
	while (strN[i] == '0')
		strN[i] = '9', i--;
	strN[i]--;
}

int main() {
	static char strN[L], strM[L];
	int a, b, c, d;

	scanf("%s%s%d%d%d%d", strN, strM, &a, &b, &c, &d);

	Matrix A = (Matrix) {a, b}, B = (Matrix) {c, d};
	minusOne(strN), minusOne(strM);
	// Answer: C=A^m, D=B*C=B*A^m, E=C*D=A^m(B*A^m)^n
	// A=[[a,b],[0,1]], B=[[c,d],[0,1]]
	// the multiply can be optimized, see operator *
	Matrix C = A ^ strM, D = C * B, E = (D ^ strN) * C;

	printf("%d", (E.a + E.b) % Mod);
	return 0;
}
