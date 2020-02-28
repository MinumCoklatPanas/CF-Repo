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

char tab[200010];
int pref[200010];
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
		memset(frek,0,sizeof(frek));
		int n,m;
		cin >> n >> m;
		pref[0] = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			pref[i] = 0;
		}
		for (int i = 1 ; i <= m ; i++)
		{
			int ta;
			cin >> ta;
			pref[0]++;
			pref[ta + 1]--;
		}
		for (int i = 1 ; i <= n ; i++) 
		{
			pref[i] += pref[i - 1];
		}
		for (int i = 1 ; i <= n ; i++)
			pref[i]++;
		for (int i = 1 ; i <= n ; i++)
			frek[tab[i] - 'a' + 1] += pref[i];
		for (int i = 1 ; i <= 26 ; i++)
			cout << frek[i] << " ";
		cout << endl;
	}
	return 0;
}