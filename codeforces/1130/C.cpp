#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

vector< vector< pair<int,int> > > cc;
char tab[55][55];
bool vis[55][55];
vector< pair<int,int> > tampung;
int n;

void dfs(int i,int j)
{
	if (i < 1) return;
	if (i > n) return;
	if (j > n) return;
	if (j < 1) return;
	if (vis[i][j]) return;
	if (tab[i][j] == '1') return;
	vis[i][j] = 1;
	tampung.push_back(make_pair(i,j));
	dfs(i - 1,j);
	dfs(i + 1,j);
	dfs(i, j - 1);
	dfs(i, j + 1);
}

int cost(int x1,int y1,int x2,int y2)
{
	return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int r1,c1,r2,c2;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
			cin >> tab[i][j];
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			if (vis[i][j] || tab[i][j] == '1') continue;
			// cout << i << " " << j << endl;
			tampung.clear();
			dfs(i,j);
			cc.push_back(tampung);
			// cout << "======================\n";
		}
	}
	// return 0;
	// cout << cc.size() << endl;
	int start = -1;
	for (int i = 0 ; i < cc.size() ; i++)
	{
		for (int j = 0 ; j < cc[i].size() ; j++)
		{
			if (cc[i][j] == make_pair(r1,c1))
			{
				start = i;
				goto hell;
			}
		}
	}
	hell:;
	int finish = -1;
	for (int i = 0 ; i < cc.size() ; i++)
	{
		for (int j = 0 ; j < cc[i].size() ; j++)
		{
			if (cc[i][j] == make_pair(r2,c2))
			{
				finish = i;
				goto school;
			}
		}
	}
	school:;
	// cout << start << " " << finish << endl;
	if (start == finish)
		cout << 0 << endl;
	else
	{
		int ans = INF; 
		for (int i = 0 ; i < cc[start].size() ; i++)
		{
			for (int j = 0 ; j < cc[finish].size() ; j++)
			{
				ans = min(ans,cost(cc[start][i].first,cc[start][i].second,cc[finish][j].first,cc[finish][j].second));
			}
		}
		cout << ans << endl;
	}
}