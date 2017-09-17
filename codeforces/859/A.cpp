#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n,mx;
	mx=0;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>k;
		mx=max(k,mx);
	}
	cout<<max(0,mx-25)<<"\n";
}