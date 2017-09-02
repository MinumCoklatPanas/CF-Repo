#include <bits/stdc++.h>
using namespace std;

int i,j,k,n,tab[100010];

int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		tab[k]++;
	}
	int maxi=0;
	for (i=1;i<=100000;i++)
	{
		int sum=tab[i-1]+tab[i]+tab[i+1];
		maxi=max(sum,maxi);
	}
	cout<<maxi<<'\n';
}
