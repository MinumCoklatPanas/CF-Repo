#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string.h>
using namespace std;

typedef unsigned long long ll;

ll kombin[110][110];

ll C(ll x,ll y)
{
	ll ans;
	if (y<=x/2){
	ans=1;
	ll ans1=1;
	ll pengali=x;
	for (ll loop=x;loop>=(x-y)+1;loop--)
	{
		ans1*=loop;
		//cout<<loop<<" loop\n";
	}
	//cout<<ans1<<"\n";
	ll ans2=1;
	for (ll loop=1;loop<=y;loop++)
	{
		ans2*=loop;
	}
	//cout<<ans1<<" "<<ans2<<"\n";
	ans=ans1/ans2;}
	else
	 {
	 	if (kombin[x][x-y]!=-1)
	 	 ans=kombin[x][x-y];
	 	else
	 	 {
	 	 	//cout<<x<<" "<<y<<"\n";
	 	 	//cout<<"yo\n";
	 		ans=C(x,x-y);
		 }
	 }
	kombin[x][y]=ans;
	return ans;
}

int main()
{
	
	//freopen("input.txt","r",stdin);
	//cout<<C(50,30)<<"\n";
	ll i,j,k,n,tab[110],mod;
	memset(kombin,-1,sizeof(kombin));
	cin>>n>>mod;
	//cout<<n<<" n\n";
	ll genap=0,ganjil=0;
	for (i=1;i<=n;i++)
	{
		cin>>tab[i];
		if (tab[i]%2==0)
		 genap++;
		else
		 ganjil++;
	}
	//cout<<ganjil<<" ganjil "<<genap<<" genap\n";
	//cout<<ganjil<<" ganjil\n";
	if (mod==1)
	{
		if (n==1)
		{
			if (ganjil==1)
			{
				cout<<1<<"\n";
				return 0;
			}
			else
			{
				cout<<0<<"\n";
				return 0;
			}
		}
		ll hitung=1;
		ll sum=0;
		ll kali=1;
		for (i=1;i<=genap;i++)
		{
			kali*=2;
		}
		//kali-=1;
		//cout<<kali<<"\n";
		while (hitung<=ganjil)
		{
			ll kombinasi=C(ganjil,hitung);
			sum+=(kombinasi*kali);
			//cout<<ganjil<<" "<<hitung<<"\n";
			//cout<<C(ganjil,hitung)<<"\n";
			hitung+=2;
		}
		//sum+=ganjil*genap;
		cout<<sum<<"\n";
		return 0;
	}
	else
	 {
	 	ll sum=1;
	 	for (i=1;i<=genap;i++)
	 	{
	 		sum*=2;
		}
		sum-=1;
		ll kali=sum;
		ll hitung=2;
		while (hitung<=ganjil)
		{
			sum+=C(ganjil,hitung)*kali+C(ganjil,hitung);
			//cout<<ganjil<<" "<<hitung<<"\n";
			//cout<<C(ganjil,hitung)<<"\n";
			hitung+=2;
		}
		sum+=1;
		cout<<sum<<"\n";
	 }
}