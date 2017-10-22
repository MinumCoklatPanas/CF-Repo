#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long ans=1;
	for (int i=1;i<=n;i++)
	 ans*=3;
	long long kurang=1;
	for (int i=1;i<=n;i++)
	{
		long long k;
		cin>>k;
		if (k%2==1)
		 kurang*=1;
		else
		 kurang*=2;
	}
	ans-=kurang;
	cout<<ans<<"\n";
}