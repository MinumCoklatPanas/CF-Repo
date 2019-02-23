#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

ll tab[110];
ll ans[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	sort(tab + 1,tab + n + 1);
	int head = 1;
	int tail = n;
	bool now = 1;
	for (int i = 1 ; i <= n ; i++)
	{
		if (now)
		{
			ans[head++] = tab[i];
		}
		else
			ans[tail--] = tab[i];
		now ^= 1;
	}
	for (int i = 1 ; i <= n ; i++)
	{
		if (i == n)
			cout << ans[i] << endl;
		else
			cout << ans[i] << " "; 
	}
}