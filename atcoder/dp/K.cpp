#include <bits/stdc++.h>
using namespace std;

int tab[110];
bool DP[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		DP[tab[i]] = 1;
	}
	for (int i = tab[1] + 1 ; i <= k ; i++)
	{
		// DP[i] = 1;
		for (int j = 1 ; j <= n ; j++)
		{
			if (tab[j] > i) break;
			DP[i] |= !DP[i - tab[j]];
		}
	}
	// for (int i = 1 ; i <= k ; i++)
	// 	cout << DP[i] << " ";
	// cout << endl;
	cout << (DP[k] ? "First" : "Second") << endl;
}