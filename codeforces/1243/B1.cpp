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
		string s,t;
		cin >> s >> t;
		int diff = 0;
		for (int i = 0 ; i < n ; i++)
			diff += (s[i] != t[i]);
		if (diff != 2 && diff != 0)
			cout << "No\n";
		else
		if (diff == 0)
			cout << "Yes\n";
		else
		{
			bool can = 0;
			for (int i = 0 ; i < n ; i++) if (s[i] != t[i])
			{
				for (int k = i + 1 ; k < n ; k++) if (s[k] != t[k])
				{
					bool cek1 = (0 || s[i] == s[k]);
					bool cek2 = (0 || t[i] == t[k]);
					can = (cek1 & cek2);
					goto hell;
				}
			}
			hell:;
			if (can)
				cout << "Yes\n";
			else
				cout << "No\n";
		}			
	}
	return 0;
}