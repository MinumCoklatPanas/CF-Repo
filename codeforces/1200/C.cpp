#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

ll cei(ll x,ll y)
{
	return ((x / y) + (x % y != 0));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,q;
	cin >> n >> m >> q;
	ll x = n / __gcd(n,m);
	ll y = m / __gcd(n,m);
	// cout << x << " " << y << endl;
	while (q--)
	{
		ll sx,sy,ex,ey;
		cin >> sx >> sy >> ex >> ey;
		if (sx == 1 && ex == 1)
		{
			ll section1 = cei(sy,x);
			ll section2 = cei(ey,x);
			if (section1 == section2)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		if (sx == 2 && ex == 2)
		{
			ll section1 = cei(sy,y);
			ll section2 = cei(ey,y);
			if (section1 == section2)
				cout << "YES\n";
			else
				cout << "NO\n";	
		}
		else
		if (sx == 1 && ex == 2)
		{
			ll section1 = cei(sy,x);
			ll section2 = cei(ey,y);
			if (section1 == section2)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			ll section1 = cei(sy,y);
			ll section2 = cei(ey,x);
			if (section1 == section2)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}