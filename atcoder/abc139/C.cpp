#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int ans = 0;
	int cnt = 0;
	for (int i = n ; i >= 1 ; i--)
	{
		if (tab[i - 1] < tab[i])
		{
			ans = max(ans,cnt);
			cnt = 0;
		}
		else
			++cnt;
	}
	cout << ans << endl;
}