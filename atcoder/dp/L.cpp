#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const
 ll INF=(ll)1e18;

ll DP[3010][3010][2];
ll tab[3010];

ll rec(ll l,ll r,ll kode)
{
	if (l>r) return 0;
	if (DP[l][r][kode]!=-INF)
	{
		return DP[l][r][kode];
	}
	if (l==r)
	{
		if (kode==1)
			DP[l][r][kode]=-tab[l];
		else
			DP[l][r][kode]=tab[l];
		return DP[l][r][kode];
	}
	if (kode==0)
	{
		ll ret=-INF;
		ll tot=0ll;
		for (int i=l;i<=l;i++)
		{
			tot+=tab[i];
			ret=max(ret,tot+rec(i+1,r,kode^1));
		}
		tot=0ll;
		for (int i=r;i>=r;i--)
		{
			tot+=tab[i];
			ret=max(ret,tot+rec(l,i-1,kode^1));
		}
		if (ret==-INF)
			ret=0ll;
		// cout<<l<<" "<<r<<" "<<kode<<" "<<ret<<" lr kode dp\n";
		return DP[l][r][kode]=ret;
	}
	else
	{
		ll ret=INF;
		ll tot=0ll;
		for (int i=l;i<=l;i++)
		{
			tot+=tab[i];
			ret=min(ret,rec(i+1,r,kode^1)-tot);
		}
		tot=0ll;
		for (int i=r;i>=r;i--)
		{
			tot+=tab[i];
			ret=min(ret,rec(l,i-1,kode^1)-tot);
		}
		if (ret==INF)
			ret=0ll;
		// cout<<l<<" "<<r<<" "<<kode<<" "<<ret<<" lr kode dp\n";
		return DP[l][r][kode]=ret;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
		for (ll j=1;j<=n;j++)
			DP[i][j][0]=DP[i][j][1]=-INF;
	for (ll i=1;i<=n;i++)
		cin>>tab[i];
	rec(1,n,0);
	cout<<DP[1][n][0]<<"\n";
}