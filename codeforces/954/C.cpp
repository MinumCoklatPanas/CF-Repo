#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll tab[200010];
set<ll> st;

ll cei(ll x,ll y)
{
	ll e=x/y;
	return (x%y==0 ? e : e+1);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	ll mx=0;
	for (ll i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	mx=max(mx,tab[i]);
	 }
	bool bisa=1;
	for (ll i=2;i<=n;i++)
	{
		ll diff=abs(tab[i]-tab[i-1]);
		if (diff>1)
		 st.insert(diff);
		if (tab[i]==tab[i-1])
		 bisa=0;
	}
	if (st.size()>1 || !bisa)
	 cout<<"NO\n";
	else
	 {
	 	if (st.size()==0)
	 	{
	 		cout<<"YES\n";
	 		cout<<1<<" "<<mx<<"\n";
		}
		else
		{
		 	ll col=*st.begin();
		 	ll row=cei(mx,col);
		 	if (col>1000000000 || row>1000000000)
		 	 cout<<"NO\n";
		 	else
		 	 {
		 	 	for (int i=1;i<n;i++)
		 	 	{
		 	 		if (abs(tab[i]-tab[i+1])==1)
		 	 		{
		 	 			if (cei(tab[i],col)!=cei(tab[i+1],col))
		 	 			{
		 	 				cout<<"NO\n";
		 	 				return 0;
						  }
					}
				}
				cout<<"YES\n";
				cout<<row<<" "<<col<<"\n";
			 }
		}
	 }
}
