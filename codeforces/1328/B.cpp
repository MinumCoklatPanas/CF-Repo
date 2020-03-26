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
	int t;
	cin >> t;
	while (t--)
	{
		string ans;
		ll n,k;
		cin >> n >> k;
		ll sum = 0;
		ll cnt = 1;
		for (int i = n - 2 ; i >= 0 ; i--)
		{
			if (sum + cnt < k)
			{
				sum += cnt;
				++cnt;
			}
			else
			{
				ll sisa = k - sum;
				for (int j = 1 ; j <= n ; j++) 
				{
					if (j <= i)
						ans += 'a';
					else
					if (j == i + 1 || j == n - sisa + 1)
						ans += 'b';
					else
						ans += 'a';
				}
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}