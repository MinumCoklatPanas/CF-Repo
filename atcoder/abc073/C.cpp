#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long i,j,k,n,tab[100010];
	map <long long,long long> mp;
	cin>>n;
	mp.clear();
	for (i=1;i<=n;i++)
	{
		cin>>tab[i];
		mp[tab[i]]++;
	}
	long long sum=0;
	for (i=1;i<=n;i++)
	{
		if (mp[tab[i]]==0) continue;
		if (mp[tab[i]]%2==1) sum++;
		
		mp[tab[i]]=0;
	}
	cout<<sum<<"\n";
}