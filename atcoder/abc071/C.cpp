#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	long long i,j,k,n,res,tab[100010];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	tab[0]=-5;
	i=n;
	long long sisi1=-1;
	long long simpan;
	while (i)
	{
		//cout<<i<<" i\n";
		bool cek=false;
		if (tab[i-1]==tab[i])
		{
			sisi1=tab[i];
			simpan=tab[i];
			cek=true;
		}
		if (cek)
		{
			simpan=i-2;
			break;
		}
		else
		 i--;
	}
	//cout<<sisi1<<" sisi\n";
	//cout<<simpan<<" simpan\n";
	if (sisi1==-1)
	{
		cout<<0<<"\n";
		return 0;
	}
	i=simpan;
	//cout<<i<<"i\n";
	long long sisi2=0;
	while (i)
	{
		//cout<<i<<" i\n";
		bool cek=false;
		if (tab[i-1]==tab[i])
		{
			sisi2=tab[i];
			break;
		}
		else
		 i--;
	}
	res=sisi1*sisi2;
	cout<<res<<"\n";
}