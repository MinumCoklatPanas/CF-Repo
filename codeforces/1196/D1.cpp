#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[2010];
int DP[5][2010];

int rec(int huruf,int pos,int cnt)
{
	if (cnt == 0) return 0;
	int trans = huruf - 1;
	if (trans == 0)
		trans = 3;
	return (tab[pos] != huruf) + rec(trans,pos - 1,cnt - 1);	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		// memset(DP,0,sizeof(DP));
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		for (int i = 1 ; i <= n ; i++)
		{
			if (s[i - 1] == 'R')
				tab[i] = 1;
			if (s[i - 1] == 'G')
				tab[i] = 2;
			if (s[i - 1] == 'B')
				tab[i] = 3;
		}
		int ans = INF;
		for (int i = k ; i <= n ; i++)	
		{
			for (int j = 1 ; j <= 3 ; j++)
				ans = min(ans,rec(j,i,k));
		}
		cout << ans << endl;
	}
}