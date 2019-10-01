#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tipe[5][200010];
// int vis[3][2][200010];
int n;

//0 itu atas 1 itu samping 2 itu bawah
//0 itu lurus 1 itu miring
bool dfs(int dariMana,int row,int col)
{
	if (row == 2 && col == n + 1) return 1;
	if (row < 1) return 0;
	if (row > 2) return 0;
	if (col > n) return 0;
	// if (vis[dariMana][row][col] != -1) return vis[dariMana][row][col];
	bool ret = 0;
	if (dariMana == 0)
	{
		if (tipe[row][col] == 0)
		{
			ret |= dfs(0,row + 1,col);
		}
		else
		{
			ret |= dfs(1,row,col + 1);
		}
	}
	else
	if (dariMana == 1)
	{
		if (tipe[row][col] == 0)
		{
			ret |= dfs(1,row,col + 1);
		}
		else
		{
			ret |= dfs(0,row + 1,col);
			ret |= dfs(2,row - 1,col);
		}
	}
	else
	if (dariMana == 2)
	{
		if (tipe[row][col] == 0)
		{
			ret |= dfs(2,row - 1,col);
		}
		else
		{
			ret |= dfs(1,row,col + 1);
		}
	}
	return ret;
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
		for (int i = 1 ; i <= 2 ; i++)
			for (int j = 1 ; j <= n ; j++)
			{
				char ta;
				cin >> ta;
				tipe[i][j] = (ta > '2');
				// vis[i][j] = 0;
			}
		bool ans = dfs(1,1,1);
		if (ans)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}