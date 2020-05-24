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

int tab[55][55];
int n;

void bfs(vector<pair<int,int>> &pos)
{
	queue< pair<int,int> > q;
	for (auto it : pos)
	{
		tab[it.first][it.second] = 0;
		q.push(it);
	}
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		int row = cur.first;
		int col = cur.second;
		if (row > 1)
		{
			if (tab[row - 1][col] == 1)
			{
				tab[row - 1][col] = 0;
				q.push({row - 1,col});
			}
		}
		if (col > 1)
		{
			if (tab[row][col - 1] == 1)
			{
				tab[row][col - 1] = 0;
				q.push({row,col - 1});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector< pair<int,int> > pos;
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
			{
				char ta;
				cin >> ta;
				tab[i][j] = ta - '0';
				if (tab[i][j])
				{
					if (i == n || j == n)
						pos.emplace_back(i,j);
				}
			}
		bfs(pos);
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++)
			{
				if (tab[i][j] == 1)
				{
					cout << "NO\n";
					goto hell;
				}
			}
		cout << "YES\n";
		hell:;
	}
	return 0;
}