#include <bits/stdc++.h>
using namespace std;

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
		int n,k1,k2;
		cin >> n >> k1 >> k2;
		bool player1 = 0;
		bool player2 = 0;
		for (int i = 1 ; i <= k1 ; i++)
		{
			int ta;
			cin >> ta;
			if (ta == n)
				player1 = 1;
		}
		for (int i = 1 ; i <= k2 ; i++)
		{
			int ta;
			cin >> ta;
			if (ta == n)
				player2 = 1;
		}
		if (player1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}