#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i,j,k,n,tab[110];
	cin>>n>>k;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	if (8*n<k)
	{
		cout<<-1<<"\n";
		return 0;
	}
	int now=k;
	for (i=1;i<=n;i++)
	{
		int kurang=abs(8-tab[i]);
		if (tab[i]>8)
		 {
		 	k-=8;
		 	tab[i+1]+=kurang;
		 }
		else
		 k-=tab[i];
		if (k<=0)
		 {
		 	cout<<i<<"\n";
		 	return 0;
		 }
	}
	if (k>0)
	 cout<<-1<<"\n";
	else
	 cout<<n<<"\n";
}
