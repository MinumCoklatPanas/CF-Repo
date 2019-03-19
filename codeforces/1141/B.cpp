#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int tab[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int i = 1;
	int ans = 0;
	while (i <= n)
	{
		while (tab[i] == 0 && i <= n)
			++i;
		int cnt = 0;
		while (tab[i] == 1 && i <= n)
		{
			++cnt;
			++i;
		}
		ans = max(ans,cnt);
	}
	int depan = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		if (tab[i] == 0) break;
		++depan;
	}
	int belakang = 0;
	for (int i = n ; i > depan ; i--)
	{
		if (tab[i] == 0) break;
		++belakang;
	}
	ans = max(ans,depan + belakang);
	cout << ans << endl;
}