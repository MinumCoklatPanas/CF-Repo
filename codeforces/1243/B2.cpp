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

int frek[30];

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
		memset(frek,0,sizeof(frek));
		string s,t;
		cin >> s >> t;
		for (int i = 0 ; i < n ; i++)
		{
			frek[s[i] - 'a']++;
			frek[t[i] - 'a']++;
		}
		bool can = 1;
		for (int i = 0 ; i < 26 ; i++)
		{
			if (frek[i] % 2 == 1)
			{
				can = 0;
				break;
			}
		}
		if (!can)
		{
			cout << "No\n";
			continue;
		}
		vector< pair<int,int> > moves;
		for (int i = 0 ; i < n ; i++)
		{
			if (s[i] == t[i]) continue;
			bool ada = 0;
			for (int j = i + 1 ; j < n ; j++)
			{
				if (s[j] == s[i])
				{
					ada = 1;
					moves.emplace_back(j,i);
					swap(s[j],t[i]);
					break;
				}
			}
			if (!ada)
			{
				for (int j = i + 1 ; j < n ; j++)
				{
					if (t[j] == s[i])
					{
						ada = 1;
						moves.emplace_back(j,j);
						moves.emplace_back(j,i);
						swap(s[j],t[j]);
						swap(s[j],t[i]);
						break;
					}
				}
			}
			if (!ada)
			{
				can = 0;
				break;
			}
		}
		if (!can || s != t)
			cout << "No\n";
		else
		{
			cout << "Yes\n";
			cout << moves.size() << endl;
			for (int i = 0 ; i < moves.size() ; i++)
				cout << moves[i].first + 1 << " " << moves[i].second + 1 << endl;
		}
	}
	return 0;
}