#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int cnt[300010];
int ix[300010];
vector<int> connect[300010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		int a;
		cin >> a;
		ix[a] = i;
	}	
	for (int i = 1 ; i <= m ; i++)
	{
		int l,r;
		cin >> l >> r;
		l = ix[l];
		r = ix[r];
		if (l > r) continue;
		connect[r].push_back(l);
		cnt[l]++;
	}
	int pos = n;	
	for (int i = n - 1 ; i >= 1 ; i--)
	{
		if (cnt[i] == pos - i)
		{
			for (int j = 0 ; j < connect[i].size() ; j++)
				cnt[connect[i][j]]--;
			--pos;
		}
	}
	int ans = n - pos;
	cout << ans << endl;
}