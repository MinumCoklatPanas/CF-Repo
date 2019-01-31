#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

char tab[510][510];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
			cin >> tab[i][j];
	int ans = 0;
	for (int i = 2 ; i < n ; i++)
		for (int j = 2 ; j < n ; j++)
		{
			if (tab[i][j] == 'X' && tab[i - 1][j - 1] == 'X' && tab[i - 1][j + 1] == 'X' && tab[i + 1][j - 1] == 'X' && tab[i + 1][j + 1] == 'X')
			 ++ ans; 
		}
	cout << ans << endl;
}