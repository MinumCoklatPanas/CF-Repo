#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector< vector< ll > > AdjMat;
ll n,k;
const ll MOD = 1e9 + 7;

vector< vector< ll > > matMul(vector< vector< ll > > a,vector< vector< ll > > b)
{
	vector< vector< ll > > ans;
	ans.resize(n);
	for (ll i = 0 ; i < n ; i++)
	{
		ans[i].resize(n,0);
		for (ll j = 0 ; j < n ; j++)
			for (ll k = 0 ; k < n ; k++)
			{
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= MOD;
			}
	}
	return ans;
}

vector< vector< ll > >  matPow(vector< vector< ll > > base,ll p)
{
	vector< vector<ll > > ans;
	ans.resize(n);
	for (ll i = 0 ; i < n ; i++)
	{
		ans[i].resize(n,0);
		for (ll j = 0 ; j < n ; j++)
			ans[i][j] = (i == j);
	}
	while (p)
	{
		if (p & 1) ans = matMul(ans,base);
		base = matMul(base,base);
		p >>= 1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	AdjMat.resize(n);
	for (ll i = 0 ; i < n ; i++)
	{
		AdjMat[i].resize(n);
		for (ll j = 0 ; j < n ; j++)
			cin >> AdjMat[i][j];
	}
	vector< vector< ll > > ans = matPow(AdjMat,k);
	ll ret = 0;
	for (ll i = 0 ; i < n ; i++)
	{
		for (ll j = 0 ; j < n ; j++)
		{
			// cout << ans[i][j] << " ";
			ret += ans[i][j];
			ret %= MOD;
		}
		// cout << endl;
	}
	cout << ret << endl;
}