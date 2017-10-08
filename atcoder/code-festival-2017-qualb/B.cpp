#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<long long,long long> mp;
	long long n;
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		mp[k]++;
	}
	long long m;
	cin>>m;
	for (long long i=1;i<=m;i++)
	{
		long long k;
		cin>>k;
		if (mp[k]>0)
		 mp[k]--;
		else
		 {
		 	cout<<"NO\n";
		 	return 0;
		 }
	}
	cout<<"YES\n";
}