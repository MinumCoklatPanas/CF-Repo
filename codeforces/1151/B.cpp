#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int tab[510][510];

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
	int sum = 0;
	for (int i = 1 ; i <= n ; i++)
		sum ^= tab[i][1];
	if (sum > 0)
	{
		cout << "TAK\n";
		for (int i = 1 ; i <= n ; i++)
			cout << 1 << " ";
		cout << endl;
		return 0;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		int cur = tab[i][1];
		for (int j = 1 ; j <= m ; j++)
		{
			int tmp = cur ^ tab[i][j];
			if (tmp != 0)
			{
				cout << "TAK\n";
				for (int k = 1 ; k <= n ; k++)
				{
					if (k == i)
					{
						cout << j << " ";
					}
					else
						cout << 1 << " ";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << "NIE\n";
	return 0;
}