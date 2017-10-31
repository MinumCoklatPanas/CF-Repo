#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,x;
	cin>>n>>x;
	long long sum=n-1;
	for (int i=1;i<=n;i++)
	{
		long long a;
		cin>>a;
		sum+=a;
	}
	cout<<(sum==x ? "YES" : "NO")<<"\n";
}
