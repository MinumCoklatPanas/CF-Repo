#include <bits/stdc++.h>
using namespace std;

long long n;
long long tab[100010];
long long DP[100010];
int k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (long long i = 1 ; i <= n ; i++)
		cin >> tab[i];
	for (int i = 1 ; i <= n ; i++)
		DP[i] = (int)1e9 + 7;
	DP[1] = 0;
	for (int i = 2 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= min(i - 1,k) ; j++)
		{
			// cout << j << endl;
			DP[i] = min(DP[i],DP[i - j] + abs(tab[i - j] - tab[i]));
		}
	}
	cout << DP[n] << endl;
}