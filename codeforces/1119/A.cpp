#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

vector<int> pos[300010];
int tab[300010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		pos[tab[i]].push_back(i);
	}
	int mx = 0;
	for (int i = 1 ; i <= n ; i++) if (pos[i].size() != 0)
	{
		if (pos[i].size() == 1)
		{
			mx = max(mx,n - pos[i][0]);
		} 
		else
		{
			int harusnya = n;
			for (int j = pos[i].size() - 1 ; j >= 0 ; j--)
			{
				if (pos[i][j] != harusnya)
				{
					mx = max(mx,harusnya - pos[i][0]);
					break;
				}
				--harusnya;
			}
		}
	}
	cout << mx << endl;
}