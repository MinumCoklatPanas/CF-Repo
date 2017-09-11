#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i,j,k,n;
	cin>>n;
	int sum=0;
	while (n--)
	{
		int l,r;
		cin>>l>>r;
		sum+=(r-l)+1;
	}
	cout<<sum<<"\n";
}