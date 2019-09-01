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
	string s,t;
	cin >> s >> t;
	int ans = s[0] == t[0];
	ans += s[1] == t[1];
	ans += s[2] == t[2];
	cout << ans << endl;
}