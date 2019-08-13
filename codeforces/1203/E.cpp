#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int frek[150010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		frek[ta]++;
	}
	for (int i = 2 ; i <= 150000 ; i++) if (frek[i])
	{
		if (!frek[i - 1])
		{
			++frek[i - 1];
			--frek[i];
		}
	}
	for (int i = 150000 ; i >= 1 ; i--) if (frek[i])
	{
		if (!frek[i + 1])
		{
			++frek[i + 1];
			--frek[i];
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= 150001 ; i++)
		ans += (frek[i] > 0);
	cout << ans << endl;

}