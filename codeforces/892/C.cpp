#include <bits/stdc++.h>
using namespace std;

int tab[2010];

int gcd(int a,int b)
{
	return (!b ? a : gcd(b,a%b));
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int satu=0;
	cin>>tab[1];
	if (n==1)
	{
		if (tab[1]==1)
		 cout<<"0\n";
		else
		 cout<<-1<<"\n";
		return 0;
	}
	int fpb=tab[1];
	satu+=(tab[1]==1);
	for (int i=2;i<=n;i++)
	{
		cin>>tab[i];
		fpb=gcd(tab[i],fpb);
		satu+=(tab[i]==1);
	}
	if (fpb!=1)
	 cout<<"-1\n";
	else
	{
		bool ada=false;
		for (int i=1;i<n;i++)
		{
			int tmp=gcd(tab[i],tab[i+1]);
			if (tmp==1)
			{
				ada=true;
				break;
			}
		}
		if (ada)
		 cout<<n-satu<<"\n";
		else
		 {
		 	int window=3000;
		 	for (int i=1;i<=n;i++)
		 	{
		 		int tmp=tab[i];
		 		for (int j=i+1;j<=n;j++)
		 		{
		 			tmp=gcd(tmp,tab[j]);
		 			if (tmp==1)
		 			{
		 				window=min(window,j-i+1);
		 				break;
					}
				}
			}
			cout<<n+window-2<<"\n";
		 }
	}
}
