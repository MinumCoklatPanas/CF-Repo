#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int i,j,k,m,n,tab[200010];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	if (n==1)
	{
		cout<<tab[1]<<"\n";
		return 0;
	}
	//case ganjil
	if (n%2==1)
	{
		k=n;
		while (k>=1)
		{
			cout<<tab[k]<<" ";
			k-=2;
		}
		k=2;
		while (k<n)
		{
			if (k==n-1)
			 cout<<tab[k]<<"\n";
			else
			 cout<<tab[k]<<" ";
			k+=2;
		}
		return 0;
	}
	k=n;
	while (k>1)
	{
		cout<<tab[k]<<" ";
		k-=2;
	}
	k=1;
	while (k<n)
	{
		if (k==n-1)
		 cout<<tab[k]<<"\n";
		else
		 cout<<tab[k]<<" ";
		k+=2;
	}
	return 0;
}