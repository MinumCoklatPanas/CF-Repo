#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll DP[15][100010];
ll BIT[15][100010];
ll tab[100010];
ll n,k;

void update(ll x,ll y,ll val)
{
	for (ll i=y;i<=n;i+=(i&-i))
	 BIT[x][i]+=val;
}

ll query(ll x,ll y)
{
	ll ans=0;
	for (ll i=y;i;i-=(i&-i))
	 {
//	 	cout<<y<<" y\n";
	 	ans+=BIT[x][i];
	 }
	return ans;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for (ll i=1;i<=n;i++)
	 cin>>tab[i];
	for (ll i=1;i<=n;i++)
	 DP[1][i]=1;
	for (ll i=2;i<=k+1;i++)
	{
		for (ll j=1;j<=n;j++)
		{
//			cout<<i<<" "<<j<<" "<<DP[i][j]<<"\n";
			DP[i][j]=query(i-1,tab[j]-1);
			update(i-1,tab[j],DP[i-1][j]);
//			for (ll o=1;o<=k+1;o++)
//			 for (ll p=1;p<=n;p++)
//			 {
//			 	if (p==n)
//			 	 cout<<BIT[o][p]<<"\n";
//			 	else
//			 	 cout<<BIT[o][p]<<" ";
//			 }
		}
	}
	for (ll i=1;i<=n;i++)
	 update(k+1,i,DP[k+1][i]);
	cout<<query(k+1,n)<<"\n";
}
