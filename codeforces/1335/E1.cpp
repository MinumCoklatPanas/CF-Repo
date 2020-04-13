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

vector< pair<int,int> > pos[35];
int tab[2010];
int pref[35][2010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 1 ; i <= 26 ; i++)
			pos[i].clear();
		memset(pref,0,sizeof(pref));
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			// pos[tab[i]].push_back(i);
			for (int j = 1 ; j <= 26 ; j++)
				pref[j][i] = pref[j][i - 1];
			pref[tab[i]][i]++;
		}
		int ans = 0;
		for (int i = 1 ; i <= n ; i++)
			for (int j = i ; j <= n ; j++)
			{
				int mx1 = 0;
				int mx2 = 0;
				int simpan = -1;
				for (int k = 1 ; k <= 26 ; k++)
				{
					int tmp = pref[k][j] - pref[k][i - 1];
					if (tmp > mx1)
					{
						mx1 = tmp;
						simpan = k;
					}
				}
				assert(simpan != -1);
				for (int k = 1 ; k <= 26 ; k++)
				{
					int kiri = pref[k][i - 1];
					int kanan = pref[k][n] - pref[k][j];
					// if ((kiri == 0 || kanan == 0) && k != simpan) continue;
					ans = max(ans,mx1 + 2 * min(kiri,kanan));
				}
			}
		cout << ans << endl;
	}
	return 0;
}