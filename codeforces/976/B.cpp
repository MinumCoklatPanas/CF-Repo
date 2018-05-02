#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cei(ll x,ll y)
{
	return (x/y)+(x%y!=0);
}

int main()
{
	ll n,m,k;
	cin>>n>>m;
	cin>>k;
	if (k<n)
	 cout<<k+1<<" "<<1<<"\n";
	else
	{
		ll mod=k-(n-1);
		mod%=m-1;
		if (mod==0)
		 mod=m-1;
		ll row=n-cei(k-(n-1),m-1)+1;
		if (row%2==0)
		 cout<<row<<" "<<mod+1<<"\n";
		else
		 cout<<row<<" "<<m-mod+1<<"\n";
	}
}
