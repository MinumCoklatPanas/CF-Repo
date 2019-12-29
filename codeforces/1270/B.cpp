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

int tab[200010];

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
		for (int i = 1 ; i <= n ; i++)
			cin >> tab[i];
		for (int i = 1 ; i < n ; i++)
		{
			if (abs(tab[i] - tab[i + 1]) > 1)
			{
				cout << "Yes\n";
				cout << i << " " << i + 1 << endl;
				goto hell;
			}
		}
		cout << "No\n";
		hell:;
	}
}