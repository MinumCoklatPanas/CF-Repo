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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll x;
	cin >> x;
	ll cur = 100;
	for (int i = 1 ; i <= 3760 ; i++)
	{
		cur += (cur / 100);
		if (cur >= x)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}