#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int l=1;
	int r=n;
	while (l<r)
	{
		int mid=(l + r)>>1;
		if ((n/mid)==1)
		 r=mid;
		else
		 l=mid+1;
	}
	if (n/l==1)
	 cout<<l<<"\n";
	else
	 cout<<r<<"\n";
}
