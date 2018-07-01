#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tab[200010];
map<ll,ll> frek;

ll cei(ll x,ll n)
{
	return (x>=0 ? (x/n)+(x%n!=0) : (x/n)-(x%n!=0));
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll n;
	cin>>n;
	ll sum=0ll;
	for (ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		tab[i]=a-i;
		sum+=tab[i];
		frek[tab[i]]++;
	}
	ll modus=-1e18;
	ll now=0ll;
	ll moduss=1e18;
	ll noww=0ll;
	for (int i=1;i<=n;i++)
	{
		if (frek[tab[i]]>now)
		{
			modus=tab[i];
			now=frek[tab[i]];
		}
		else
		if (frek[tab[i]]==now && tab[i]>modus)
		{
			modus=tab[i];
			now=frek[tab[i]];
		}
		if (frek[tab[i]]>noww)
		{
			moduss=tab[i];
			noww=frek[tab[i]];
		}
		else
		if (frek[tab[i]]==noww && tab[i]<moduss)
		{
			moduss=tab[i];
			noww=frek[tab[i]];
		}
	}
	ll bawah=sum/n;
	ll atas=bawah+1;
	ll satunya=bawah-1;
	ll ans;
	ll satu=0ll;
	ll dua=0ll;
	ll tiga=0ll;
	ll testes=0ll;
	ll wtf=0ll;
	for (int i=1;i<=n;i++)
	{
		satu+=llabs(tab[i]-bawah);
		dua+=llabs(tab[i]-atas);
		tiga+=llabs(tab[i]-satunya);
		testes+=llabs(tab[i]-modus);
		wtf+=llabs(tab[i]-moduss);
	}
//	cout<<satu<<" "<<dua<<" "<<tiga<<" "<<testes<<" "<<wtf<<"\n";
	ans=min(min(satu,dua),min(tiga,testes));
	ans=min(ans,wtf);
	ll tengah1,tengah2;
	sort(tab+1,tab+n+1);
	if (n%2==0)
	{
		tengah1=tab[n/2];
		tengah2=tab[(n/2)+1];
	}
	else
	{
		tengah1=tab[(n/2)+1];
		tengah2=tengah1;
	}
	ll asu1=0ll,asu2=0ll;
	for (int i=1;i<=n;i++)
	{
		asu1+=llabs(tab[i]-tengah1);
		asu2+=llabs(tab[i]-tengah2);
	}
	ans=min(ans,min(asu1,asu2));
	cout<<ans<<"\n";
}