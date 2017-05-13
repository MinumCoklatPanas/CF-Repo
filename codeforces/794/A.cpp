#include <iostream>
#include <algorithm>
using namespace std;

int i,j,k,sum,a,b,c,tab[100010],n;
int *cari;

int main()
{
	cin>>a>>b>>c;
	cin>>n;
	sum=0;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	cari=lower_bound(tab+1,tab+n,a);
	int in=cari-tab;
	//cout<<in<<"\n";
	if ((b<tab[in])&&(tab[in]<c))
	 sum++;
	//carikiri
	int x=in-1;
	int d=tab[x];
	bool bo=true;
	while ((bo)&&(x>=1))
	{
		if (d<=b)
		 bo=false;
		else
		 {
		 	sum++;
		 	x--;
		 	d=tab[x];
		 }
	}
	//carikanan
	x=in+1;
	d=tab[x];
	bo = true;
	while ((bo)&&(x<=n))
	{
		//cout<<"a\n";
		if (d>=c)
		 bo=false;
		else
		 {
		 	sum++;
		 	x++;
		 	d=tab[x];
		 }
	}
	cout<<sum<<"\n";
	return 0;
}
