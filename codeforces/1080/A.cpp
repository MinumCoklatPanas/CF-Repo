#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cei(ll x,ll y)
{
	return (x/y)+(x%y!=0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll satu=2*n;
	ll dua=5*n;
	ll tiga=8*n;
	ll ans=cei(satu,k)+cei(dua,k)+cei(tiga,k);
	cout<<ans<<"\n";
}