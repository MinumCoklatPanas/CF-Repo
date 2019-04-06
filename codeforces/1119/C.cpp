#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab1[510][510];
int tab2[510][510];
bool beda[510][510];

int cols[510];
int rows[510];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			cin >> tab1[i][j];
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			cin >> tab2[i][j];
	int cnt = 0;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			if (tab1[i][j] ^ tab2[i][j])
			{
				// cout << i << " " << 
				rows[i]++;
				cols[j]++;
			}
		}
	for (int i = 1 ; i <= n ; i++)
	{
		// cout << rows[i] << endl;
		if (rows[i] % 2 == 1)
		{
			cout << "No\n";
			return 0;
		}
	}
	for (int i = 1 ; i <= m ; i++)
	{
		if (cols[i] % 2 == 1)
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

}