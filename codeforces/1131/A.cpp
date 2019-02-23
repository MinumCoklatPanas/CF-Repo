#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

ll w1,h1,w2,h2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> w1 >> h1 >> w2 >> h2;
	ll ans = 2 *(h1 + h2 + 2) + w1 + w2 + (abs(w1-w2));
	cout << ans << endl;
}