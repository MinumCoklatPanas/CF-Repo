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
		string s;
		cin >> s;
		bool sama_semua = 1;
		for (int i = 0 ; i < s.length() ; i++)
		{
			if (s[i] != s[0])
			{
				sama_semua = 0;
				break;
			}
		}
		if (sama_semua)
			cout << s << endl;
		else
		{
			for (int i = 0 ; i < s.length() ; i++)
				cout << "10";
			cout << endl;
		}
	}
	return 0;
}