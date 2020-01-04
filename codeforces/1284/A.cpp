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

string s[25];
string t[25];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
		cin >> s[i];
	for (int i = 1 ; i <= m ; i++)
		cin >> t[i];
	int q;
	cin >> q;
	while (q--)
	{
		int ta;
		cin >> ta;
		string ans;
		string kiri,kanan;
		int ix = ta % n;
		if (ix == 0)
			ix = n;
		kiri = s[ix];
		ix = ta % m;
		if (ix == 0)
			ix = m;
		kanan = t[ix];
		ans = kiri + kanan;
		cout << ans << endl;
	}
	return 0;
}