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
	cin >> s;
	reverse(s.begin(),s.end());
	int cnt = 0;
	for (int i = 0 ; i + 1 < s.length() ; i++) if (i % 2 == 0)
		++cnt;
	if ((s.length()) % 2 == 1)
	{
		bool nol = 1;
		for (int i = 0 ; i + 1 < s.length() ; i++)
		{
			if (s[i] == '1')
			{
				// cout << i << endl;
				nol = 0;
				break;
			}
		}
		// cout << nol << endl;
		cnt += !nol;
	}
	cout << cnt << endl;
}