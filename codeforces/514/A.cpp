#include <iostream>
using namespace std;

int digit (long long x)
{
	int ret=0;
	while (x>0)
	 {
	 	ret++;
	 	x=x/10;
	 }
	 return ret;
}

int main()
{
	long long i,j,n,tab[20];
	//cout<<digit(27)<<"\n";
	cin>>n;
	//cout<<digit(n)<<"\n";
	j=n;
	for (i=digit(n);i>=1;i--)
	{
		tab[i]=j%10;
		j=j/10;
	}
	if ((tab[1]>=5)&&(tab[1]!=9))
	 tab[1]=9-tab[1];
	for (i=2;i<=digit(n);i++)
	{
		if (tab[i]>=5)
		 tab[i]=9-tab[i];
	}
	for (i=1;i<=digit(n);i++)
	{
		if (i==digit(n))
		 cout<<tab[i]<<"\n";
		else
		 cout<<tab[i];
	}
	return 0;
}
