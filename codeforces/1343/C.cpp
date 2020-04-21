#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

ll dpLength[2];
ll dpSum[2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		dpLength[0] = dpLength[1] = 0;
		dpSum[0] = dpSum[1] = -INFF;
		ll n;
		cin >> n;
		for (ll i = 1 ; i <= n ; i++)
		{
			ll ta;
			cin >> ta;
			if (ta < 0)
			{
				if (dpLength[0] == 0)
				{
					dpLength[1] = 1;
					dpSum[1] = max(dpSum[1],ta);
				}
				else
				{
					if (dpLength[0] + 1 > dpLength[1])
					{
						dpLength[1] = dpLength[0] + 1;
						dpSum[1] = dpSum[0] + ta;
					}
					else
					{
						dpSum[1] = max(dpSum[1],dpSum[0] + ta);
					}
				}
			}
			else
			{
				if (dpLength[1] == 0)
				{
					dpLength[0] = 1;
					dpSum[0] = max(dpSum[0],ta);
				}
				else
				{
					if (dpLength[1] + 1 > dpLength[0])
					{
						dpLength[0] = dpLength[1] + 1;
						dpSum[0] = dpSum[1] + ta;
					}
					else
					{
						dpSum[0] = max(dpSum[0],dpSum[1] + ta);
					}
				}
			}
		}
		if (dpLength[0] == dpLength[1])
			cout << max(dpSum[0],dpSum[1]) << endl;
		else
		if (dpLength[0] > dpLength[1])
			cout << dpSum[0] << endl;
		else
			cout << dpSum[1] << endl;
	}
	return 0;
}