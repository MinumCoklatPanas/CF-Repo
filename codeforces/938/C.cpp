#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll t;
	cin>>t;
	while (t--)
	{
		ll a;
		cin>>a;
		if (a==0)
		{
			cout<<1<<" "<<1<<"\n";
			continue;
		}
		ll akar=(ll)sqrt(a+1);
		if ((akar*akar)==a+1)
		{
//			cout<<"yo\n";
			cout<<akar<<" "<<akar<<"\n";
			continue;
		}
		akar=(ll)sqrt(a);
		bool ada=false;
		ll n,m;
		for (ll i=1;i<=akar;i++)
		{
			if (a%i==0)
			{
				ll tambah=a/i;
				ll kurang=i;
//				cout<<tambah<<" "<<kurang<<" tk\n";
				ll x=tambah-kurang;
//				cout<<x<<" x\n";
				if (x<=0) continue;
				if (x%2!=0) continue;
//				cout<<" yo\n";
				x/=2;
				n=x+kurang;
//				cout<<n<<" n\n";
				ll satunya=(ll)sqrt(n*n-a);
//				cout<<satunya<<" satunya\n";
//				m=n/satunya;
				ll bawah=1;
				ll atas=n;
				bool dapat=false;
				ll mid=(bawah+atas)>>1;
//				cout<<mid<<" mid\n";
				m=-1;
				while (bawah<=atas)
				{
//					cout<<mid<<" mid\n";
//					cout<<atas<<" "<<bawah<<" before\n";
					if (n/mid==satunya)
					{
						m=mid;
						dapat=true;
						break;
					}
					if (n/mid<satunya)
					 atas=mid-1;
					else
					 bawah=mid+1;
//					cout<<atas<<" "<<bawah<<" after\n";
					mid=(atas+bawah)>>1;
				}
//				while
//				cout<<m<<" m\n";
				if (m<=1) continue;
				ada=true;
				break;
			}
		}
		if (ada)
		 cout<<n<<" "<<m<<"\n";
		else
		 cout<<-1<<"\n";
	}
}
