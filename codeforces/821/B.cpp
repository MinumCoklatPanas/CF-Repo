#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll pref(ll x)
{
	ll ans=(x*(x+1))/2;
	return ans;
}

int main()
{
	ll i,j,k,n,m,b;
	ll max=0;
	cin>>m>>b;
	ll cari=m*b;
	while (cari%m!=0)
	 cari--;
	while (cari>0)
	{
		ll pasang=b-(cari/m);
		if (pasang<0)
		 break;
		//cout<<cari<<" "<<pasang<<" pasang cari\n";
		ll ans=(pref(cari)*(pasang+1))+(pref(pasang)*(cari+1));
		//cout<<ans<<"\n";
		if (ans>max)
		 max=ans;
		 cari-=m;
	}
	cout<<max<<"\n";
}
