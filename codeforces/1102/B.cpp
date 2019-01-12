#include <bits/stdc++.h>
using namespace std;

vector<int> pos[5010];
int tab[5010];
int color[5010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		pos[tab[i]].push_back(i);
	}
	for (int i = 1 ; i <= n ; i++)
	{
		if (pos[tab[i]].size() > k)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	int now = 0;
	for (int i = 1 ; i <= 5000 ; i++)
	{
		for (int j = 0 ; j < pos[i].size() ; j++)
		{
			color[pos[i][j]] = now++;
			now %= k;
		}
	}
	for (int i = 1 ; i <= n ; i++)
		cout << color[i] + 1 << " ";
	cout << endl;
}