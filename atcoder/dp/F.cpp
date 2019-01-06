#include <bits/stdc++.h>
using namespace std;

int DP[3010][3010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	string ans;
	ans = "";
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
		{
			if (s[i - 1] == t[j -1])
			{
				// cout << i << " " << j << endl;
				DP[i][j] = DP[i -1][j - 1] + 1;
				// ans += s[i - 1];
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j],DP[i][j - 1]);
			}
		}
	int i = n; int j = m;
	while (i >= 1 && j >= 1)
	{
		if (s[i - 1] == t[j - 1])
		{
			ans += s[i - 1];
			--i; --j;
		}
		else
		{
			if (DP[i - 1][j] > DP[i][j - 1])
				--i;
			else
				--j;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans << endl;
}