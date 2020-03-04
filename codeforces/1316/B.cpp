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
		string s;
		cin >> n >> s;
		string tmp;
		tmp = s;
		string ans;
		ans = s;
		int ix = 1;
		for (int i = 1 ; i <= n ; i++)
		{
			string kanan = tmp.substr(i - 1,n - i + 1);
			// cout << kanan << endl;
			string kiri;
			kiri = "";
			if (i > 1)
				kiri = tmp.substr(0,i - 1);
			if (i % 2 == (n % 2))
				reverse(kiri.begin(),kiri.end());
			kanan += kiri;
			// cout << kanan << endl;
			if (kanan < ans)
			{
				ans = kanan;
				ix = i;
			}
		}
		cout << ans << endl;
		cout << ix << endl;
	}
	return 0;
}