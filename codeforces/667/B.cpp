#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	ll tab[100010];
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	if (n==3)
	{
		bool cek=true;
		cek&=(tab[1]+tab[2]>tab[3]);
		cek&=(tab[1]+tab[3]>tab[2]);
		cek&=(tab[2]+tab[3]>tab[1]);
		if (cek)
		 cout<<"0\n";
		else
		 cout<<(tab[3]-(tab[1]+tab[2])+1)<<"\n";
	}
	else
	 {
	 	ll sum=0;
	 	for (int i=1;i<n;i++)
	 	 sum+=tab[i];
	 	cout<<(tab[n]-sum+1)<<"\n";
	 }
}
