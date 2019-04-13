#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int asu[110][110];
int tab[110][110];
int column[110];
int row[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(asu,-1,sizeof(asu));
	int n,m,h;
	cin >> n >> m >> h;
	for (int i = 1 ; i <= m ; i++)
		cin >> column[i];
	for (int i = 1 ; i <= n ; i++)
		cin >> row[i];
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			cin >> tab[i][j];
			if (tab[i][j] == 0)
				asu[i][j] = 0;
		}
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			if (asu[i][j] == -1)
				asu[i][j] = min(row[i],column[j]);
		}
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= m ; j++)
		{
			cout << asu[i][j] << " ";
		}
		cout << endl;
	}
}