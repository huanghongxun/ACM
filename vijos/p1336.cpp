#include <iostream>
using namespace std;
int x[1100], y[1100], F[1100];
int main()
{
	const double s2 = 141.4213;
	int m, n, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	cin >> x[i] >> y[i];
	for (int i = 0; i < k; i++)
	{
	    for (int j = i + 1; j < k; j++)
	    {
	        if (x[i] > x[j])
	        {
	            swap (x[i], x[j]);
	            swap (y[i], y[j]);
	        }
	    }
	}

	for (int i = 0; i < k; i++)
	{
	    for (int j = 0; x[j] < x[i]; j++)
	    {
	        if (F[j] > F[i] && y[j] < y[i]) F[i] = F[j];
	    }
	    F[i]++;
	}

	int max(0);
	for (int i = 0; i < k; i++) if (F[i] > max) max = F[i];

	double l = double(max) * s2 + 100 *(n  + m - 2 * max);
	max = l + 0.5000;
	cout << max;

	return 0;
}