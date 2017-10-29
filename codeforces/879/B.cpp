#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,k;
	cin>>n>>k;
	long long tab[1000];
	long long mx=-1;
	for (long long i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	mx=max(mx,tab[i]);
	 }
	for (long long i=1;i<=n;i++)
	{
		long long now=tab[i];
		long long count=0;
		if (i!=1)
		 ++count;
		if (now==mx)
		 {
		 	cout<<mx<<"\n";
		 	return 0;
		 }
		for (long long j=i+1;j<=n;j++)
		{
			if (tab[j]>tab[i]) break;
			++count;
		}
		if (count>=k)
		{
			cout<<now<<"\n";
			return 0;
		}
	}
}
