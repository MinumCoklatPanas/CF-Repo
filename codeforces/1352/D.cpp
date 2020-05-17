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

int tab[1010];

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
		for (int i = 1 ; i <= n ; i++)
			cin >> tab[i];
		int tot[2] = {0,0};
		int lastMove = 0;
		int l = 1;
		int r = n;
		int curPlayer = 0;
		int turn = 0;
		while (l <= r)
		{
			if (curPlayer == 0)
			{
				int tmp = 0;
				while (tmp <= lastMove && l <= r)
				{
					tmp += tab[l];
					++l;
				}
				lastMove = tmp;
				tot[curPlayer] += tmp;
			}
			else
			{
				int tmp = 0;
				while (tmp <= lastMove && l <= r)
				{
					tmp += tab[r];
					--r;
				}
				lastMove = tmp;
				tot[curPlayer] += tmp;	
			}
			curPlayer ^= 1;
			++turn;
		}	
		cout << turn << " " << tot[0] << " " << tot[1] << endl;
	}
	return 0;
}