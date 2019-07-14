#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int row[50010];
int col[50010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		for (int i = 0 ; i < n ; i++)
			row[i] = 0;
		for (int i = 0 ; i < m ; i++)
			col[i] = 0;
		vector< string > tab;
		for (int i = 1 ; i <= n ; i++)
		{
			string ta;
			cin >> ta;
			tab.push_back(ta);
		}
		// return 0;
		for (int i = 0 ; i < n ; i++)
		{
			int sum = 0;
			for (int j = 0 ; j < m ; j++)
			{
				sum += (tab[i][j] == '*');
				col[j] += (tab[i][j] == '*');
			}
			row[i] = sum;
		}
		// return 0;
		int ans = INF;
		for (int i = 0 ; i < n ; i++)
		{
			int target = m + n - 1;
			for (int j = 0 ; j < m ; j++)
			{
				int tot = row[i] + col[j] - (tab[i][j] == '*');
				ans = min(ans,target - tot);
			}
		}
		cout << ans << endl;
	}
}