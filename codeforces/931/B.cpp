#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	if (a>b)
	 swap(a,b);
	int round=(int)log2(n);
	int total=n;
	int l=1;
	int r=n;
	for (int i=round;i>=1;i--)
	{
//		cout<<l<<" "<<r<<"\n";
		int half=(l+r)>>1;
//		cout<<half<<"\n";
		if ((a<=half) && (b>half))
		{
			if (i==round)
			 cout<<"Final!\n";
			else
			 cout<<i<<"\n";
			return 0;
		}
		if (a>half)
		 l=half+1;
		else
		 r=half;
		total/=2;
	}
}
