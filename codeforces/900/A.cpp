#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int posX=0,negX=0;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		if (x<0) ++negX;
		 else ++posX;
	}
	if (posX==0 || negX==0 || posX==1 || negX==1)
	 cout<<"YES\n";
	else
	 cout<<"NO\n";
}
