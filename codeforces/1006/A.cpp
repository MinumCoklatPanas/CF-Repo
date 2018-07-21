#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int tab[1010];
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	if (tab[i]%2==0)
	 	 --tab[i];
	 }
	for (int i=1;i<=n;i++)
	{
		if (i==n)
		 cout<<tab[i]<<"\n";
		else
		 cout<<tab[i]<<" ";
	}
}