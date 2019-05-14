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
	string s;
	int n;
	int x,y;
	cin >> n >> x >> y >> s;
	string tmp;
	for (int i = n - x ; i < n ; i++)
		tmp += s[i];
	assert(tmp.size() == x);
	// cout << tmp << endl;
	reverse(tmp.begin(),tmp.end());
	int ans = 0;
	for (int i = 0 ; i < x ; i++)
	{
		if (i == y)
			ans += (tmp[i] == '0');
		else
			ans += (tmp[i] == '1');
	}
	cout << ans << endl;
}