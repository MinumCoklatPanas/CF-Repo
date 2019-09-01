#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b;
	cin >> a >> b;
	int cur = 1;
	int ans = 0;
	while (cur < b)
	{
		++ans;
		cur += (a - 1);
	}
	cout << ans << endl;
}