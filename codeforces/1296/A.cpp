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
		int n;
		cin >> n;
		int ganjil = 0,genap = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			int ta;
			cin >> ta;
			ganjil += ta % 2;
			genap += !(ta % 2);
		}
		if (n % 2 == 0)
		{
			if ((ganjil > 0) && (genap > 0))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			if (ganjil > 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}