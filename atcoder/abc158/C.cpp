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
	int a,b;
	cin >> a >> b;
	int ans = -1;
	for (int i = 1 ; i <= 1000000 ; i++)
	{
		double aa = floor(1.0 * i * 0.08);
		double bb = floor(1.0 * i * 0.1);
		if (aa == a && bb == b)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}