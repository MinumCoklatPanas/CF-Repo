#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool adj[110][110];
int tab[1000010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
		{
			char ta;
			cin >> ta;
			adj[i][j] = (ta == '1');
		}
	}
	int m;
	cin >> m;
	for (int i = 1 ; i <= m ; i++)
		cin >> tab[i];
	int ptr = 2;
	vector<int> ans;
	ans.push_back(tab[1]);
	while (ptr < m)
	{
		int cur = ans.back();
		int nxt = tab[ptr + 1];
		if (!adj[cur][nxt] && cur != nxt)
		{
			ans.push_back(tab[ptr + 1]);
			ptr += 2;
		}
		else
		{
			ans.push_back(tab[ptr]);
			ptr++;
		}
	}
	if (ptr == m)
		ans.push_back(tab[ptr]);
	cout << ans.size() << endl;
	for (int i = 0 ; i < ans.size() ; i++)
		cout << ans[i] << " ";
	cout << endl;
}