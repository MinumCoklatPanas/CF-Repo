#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int DP[110][110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s,t,p;
		cin >> s >> t >> p;
		if (s.length() > t.length())
		{
			cout << "NO\n";
			continue;
		}
		memset(DP,0,sizeof(DP));
		for (int i = 1 ; i <= s.length() ; i++)
		{
			for (int j = 1 ; j <= t.length() ; j++)
			{
				if (s[i - 1] == t[j - 1])
				{
					DP[i][j] = 1 + DP[i - 1][j - 1];
				}
				else
				{
					DP[i][j] = max(DP[i - 1][j],DP[i][j - 1]);
				}
				// cout << DP[i][j] << " " << i << " "  << j << " " << s[i - 1] << t[j - 1] << endl;
				// cout << DP[i][j] << " ";
			}
			// cout << endl;

		}
		// cout << DP[s.length()][t.length()] << endl;
		// continue;
		if (DP[s.length()][t.length()] != s.length())
		{
			cout << "NO\n";
			continue;
		}
		// continue;
		// vector<int> masuk;
		bool masuk[110];
		memset(masuk,0,sizeof(masuk));
		int x = s.length();
		int y = t.length();
		while (x > 0 && y > 0)
		{
			// cout << x << " " << y << endl;
			if (s[x - 1] == t[y - 1])
			{
				masuk[y] = 1;
				// cout << "yo\n";
				// masuk.push_back(y);
				--x;
				--y;
			}
			else
			if ((DP[x - 1][y] > DP[x][y - 1]) && (x > 1))
				--x;
			else
				--y;
		}
		// if (s[0] == t[0])
		// 	masuk[1] = 1;
		string sisa;
		for (int i = 0 ; i < t.length() ; i++) if (!masuk[i + 1])
		{
			// cout << i << endl;
			sisa += t[i];
		}
		// cout << sisa << endl;
		// assert(sisa.length() == t.length() - DP[s.length()][t.length()]);
		int cnt1[30];
		int cnt2[30];
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for (int i = 0 ; i < sisa.length() ; i++)
			cnt1[sisa[i] - 'a' + 1]++;
		for (int i = 0 ; i < p.length() ; i++)
			cnt2[p[i] - 'a' + 1]++;
		bool bisa = 1;
		for (int i = 1 ; i <= 26 ; i++)
		{
			if (cnt2[i] < cnt1[i])
			{
				bisa = 0;
				break;
			}
		}
		if (bisa)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}