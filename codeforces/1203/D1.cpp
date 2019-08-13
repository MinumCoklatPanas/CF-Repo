#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

deque<int> asu[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin >> s >> t;
	int ans = 0;
	for (int i = 0 ; i < s.length() ; i++)
	{
		for (int j = i ; j < s.length() ; j++)
		{
			for (int k = 0 ; k < 26 ; k++)
				asu[k].clear();
			for (int k = 0 ; k < s.length() ; k++)
				asu[s[k] - 'a'].push_back(k);
			bool bisa = 1;
			int last = 0;
			for (int k = 0 ; k < t.length() ; k++)
			{
				while (!asu[t[k] - 'a'].empty() && (asu[t[k] - 'a'].front() < last))
					asu[t[k] - 'a'].pop_front();
				while (!asu[t[k] - 'a'].empty() && (i <= asu[t[k] - 'a'].front() && asu[t[k] - 'a'].front() <= j))
					asu[t[k] - 'a'].pop_front();
				if (asu[t[k] - 'a'].empty())
				{
					// cout << k << endl;
					bisa = 0;
					break;
				}
				last = asu[t[k] - 'a'].front();
				asu[t[k] - 'a'].pop_front();
			}
			if (bisa)
			{
				// cout << i << " " << j << endl;
				ans = max(ans,j - i + 1);
			}
		}
	}
	cout << ans << endl;
}