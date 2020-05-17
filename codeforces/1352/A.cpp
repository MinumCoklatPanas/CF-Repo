#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int dig(int x)
{
	int ret = 0;
	while (x)
	{
		ret++;
		x /= 10;
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
		vector< int > ans;
		int n;
		cin >> n;
		int pengali = 1;
		while (n)
		{
			int cur = n % 10;
			cur *= pengali;
			if (cur != 0)
				ans.push_back(cur);
			pengali *= 10;
			n /= 10;
		}
		cout << ans.size() << endl;
		for (auto it : ans)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}