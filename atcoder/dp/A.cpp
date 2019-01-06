#include <bits/stdc++.h>
using namespace std;

long long n;
long long tab[100010];
long long DP[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (long long i = 1 ; i <= n ; i++)
		cin >> tab[i];
	DP[2] = abs(tab[2] - tab[1]);
	for (long long i = 3 ; i <= n ; i++)
	{
		DP[i] = min(DP[i - 1] + abs(tab[i] - tab[i - 1]),DP[i - 2] + abs(tab[i] - tab[i - 2]));
	}
	cout << DP[n] << endl;
}