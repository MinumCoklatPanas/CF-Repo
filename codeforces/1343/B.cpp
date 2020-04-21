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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		if (n % 4 != 0)
			cout << "NO\n";
		else
		{
			cout << "YES\n";
			ll batas = (n / 4) * 5;
			vector< int > ganjil;
			vector< int > genap;
			for (int i = 1 ; i <= batas ; i += 5)
			{
				int mid = i + 2;
				for (int j = i ; j <= i + 5 - 1; j++) if (j != mid)
				{
					if (j % 2 == 0)
						genap.push_back(j);
					else
						ganjil.push_back(j);
				}
			}
			for (auto it : genap)
				cout << it << " ";
			for (auto it : ganjil)
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}