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

int dp[2010][2010]; //[tidur berapa][jam berapa]
bool ada[2010][2010];
int tab[2010];

bool between(int l,int r,int x)
{
	return  ((l <= x) && (x <= r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,h,l,r;
	cin >> n >> h >> l >> r;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	dp[0][0] = 0;
	ada[0][0] = 1;
	int ans = 0;
	for (int i = 1 ; i <= n ; i++)
		for (int j = 0 ; j < h ; j++)
		{
			if (ada[i - 1][j])
			{
				ada[i][(j + tab[i]) % h] = 1;
				dp[i][(j + tab[i])  % h] = max(dp[i][(j + tab[i])  % h],dp[i - 1][j] + between(l,r,(j + tab[i]) % h));
				ans = max(ans,dp[i][(j + tab[i])  % h]);
				ada[i][(j + tab[i] - 1) % h] = 1;
				dp[i][(j + tab[i] - 1)  % h] = max(dp[i][(j + tab[i] - 1)  % h],dp[i - 1][j] + between(l,r,(j + tab[i] - 1) % h));
				ans = max(ans,dp[i][(j + tab[i] - 1)  % h]);
			}
		}
	cout << ans << endl;
	return 0;
}