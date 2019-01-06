#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int x,int y)
{
	return ((x % MOD) + (y % MOD)) % MOD;
}

char tab[1010][1010];
int DP[1010][1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			cin >> tab[i][j];
	DP[1][1] = 1;
	for (int i = 2 ; i <= m ; i++)
		DP[1][i] = (tab[1][i] == '.') * DP[1][i - 1];
	for (int i = 2 ; i <= n ; i++)
		DP[i][1] = (tab[i][1] == '.') * DP[i - 1][1];
	for (int i = 2 ; i <= n ; i++)
		for (int j = 2 ; j <= m ; j++)
		{
			if (tab[i][j] == '#')
				DP[i][j] = 0;
			else
				DP[i][j] = add(DP[i - 1][j],DP[i][j - 1]);
		}
	// for (int i = 1 ; i <= n ; i++)
	// {
	// 	for (int j = 1 ; j <= m ; j++)
	// 		cout << DP[i][j] << " ";
	// 	cout << endl;
	// }
	cout << DP[n][m] << endl;
}