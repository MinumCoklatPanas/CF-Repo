#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int ans[2][100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n % 2 == 0)
		cout << "NO\n";
	else
	{
		ans[0][1] = 1;
		ans[1][n] = 2 * n;
		int cur = 2;
		int ptr[2];
		ptr[0] = 2;
		ptr[1] = 1;
		int pos = 1;
		for (int i = 1 ; i < n ; i++)
		{
			ans[pos][ptr[pos]++] = cur++;
			ans[pos][ptr[pos]++] = cur++;
			pos ^= 1;
		}
		cout << "YES\n";
		for (int i = 1 ; i <= n ; i++)
			cout << ans[0][i] << " ";
		for (int i = 1 ; i <= n ; i++)
			cout << ans[1][i] << " ";
		cout << endl;
	}
}