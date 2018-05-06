#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool sudah[110];

bool cmp(ll p,ll q)
{
	return p>q;
}

int main()
{
	memset(sudah,0,sizeof(sudah));
	ll n;
	cin>>n;
	ll tab[110];
	ll sisa=n;
	vector<ll> ans;
	for (ll i=1;i<=n;i++)
	{
		cin>>tab[i];
		if (tab[i]%2==1)
		{
			ans.push_back(tab[i]);
			sudah[i]=1;
			--sisa;
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	if (ans.size()==0)
	{
		ans.push_back(tab[1]);
		sudah[1]=1;
		--sisa;
		while (sisa>0)
		{
			ll kiri=ans[0];
			ll kanan=ans[ans.size()-1];
			for (ll i=1;i<=n;i++)
			{
				if (sudah[i]) continue;
				if (tab[i]*2==kiri || kiri*3==tab[i])
				{
					vector<ll>::iterator it=ans.begin();
					it=ans.insert(it,tab[i]);
					sudah[i]=1;
					kiri=tab[i];
					--sisa;
				}
				else
				 if (tab[i]==kanan*2 || 3*tab[i]==kanan)
				 {
				 	ans.push_back(tab[i]);
				 	sudah[i]=1;
				 	kanan=tab[i];
				 	--sisa;
				 }
			}
		}
		goto hell;
	}
	while (sisa>0)
	{
		ll ujung=ans[ans.size()-1];
		for (ll i=1;i<=n;i++)
		{
			if (sudah[i]) continue;
			if (tab[i]==ujung*2 || 3*tab[i]==ujung)
			{
				ujung=tab[i];
				sudah[i]=1;
				--sisa;
				ans.push_back(tab[i]);
			}
		}
	}
	hell:;
	assert(ans.size()==n);
	for (ll i=0;i<n;i++)
	{
		if (i==n-1)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
}
