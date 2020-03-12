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

int tab[5010];
int frek[2][5010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(frek,0,sizeof(frek));
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			frek[1][tab[i]]++;
		}
		bool ada = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			--frek[1][tab[i]];
			for (int j = 1 ; j <= n ; j++) if ((frek[0][j] > 0) && (frek[1][j] > 0))
			{
				ada = 1;
				break;
			}
			++frek[0][tab[i]];
		}
		if (ada)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}