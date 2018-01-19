#include <bits/stdc++.h>
using namespace std;

bool valid(int x)
{
	return (x%10==7 || x/10==7);
}

int main()
{
	int x;
	cin>>x;
	int hh,mm;
	cin>>hh>>mm;
	int ans=0;
	while (!valid(hh) && !valid(mm))
	{
//		cout<<hh<<" "<<mm<<"\n";
		mm-=x;
		if (mm<0)
		{
			mm+=60;
			--hh;
		}
		if (hh<0)
		 hh+=24;
		++ans;
	}
	cout<<ans<<"\n";
}
