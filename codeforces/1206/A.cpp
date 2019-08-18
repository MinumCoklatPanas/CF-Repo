#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int mx1 = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		mx1 = max(mx1,ta);
	}
	int m;
	cin >> m;
	int mx2 = 0;
	for (int i = 1 ; i <= m ; i++)
	{
		int ta;
		cin >> ta;
		mx2 = max(mx2,ta);
	}
	cout << mx1 << " " << mx2 << endl;
}