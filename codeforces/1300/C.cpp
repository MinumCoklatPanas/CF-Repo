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

int cnt[35];
int tab[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		for (int j = 0 ; j <= 30 ; j++) if (tab[i] & (1 << j))
			cnt[j]++;
	}
	int depan = 1;
	int mx = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		int tmp = 0;
		for (int j = 0 ; j <= 30 ; j++) if ((tab[i] & (1 << j)) && (cnt[j] == 1))
			tmp += (1 << j);
		if (tmp > mx)
		{
			depan = i;
			mx = tmp;
		}
	}
	cout << tab[depan] << " ";
	for (int i = 1 ; i <= n ; i++) if (i != depan)
		cout << tab[i] << " ";
	cout << endl;
	return 0;
}