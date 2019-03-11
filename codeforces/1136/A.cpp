#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

pair<int,int> tab[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i].first >> tab[i].second;
	int k;
	cin >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		if (tab[i].first <= k && k <= tab[i].second)
		{
			cout << n - (i - 1) << endl;
			return 0;
		}
	}
}