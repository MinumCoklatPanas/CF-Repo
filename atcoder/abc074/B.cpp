#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n>>k;
	int sum=0;
	for (i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		int ans=min(x,abs(k-x));
		sum+=2*ans;
	}
	cout<<sum<<"\n";
}