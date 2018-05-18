#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	cin>>n;
	ll Ymax=-1e12,Ymin=1e12,Xmax=-1e12,Xmin=1e12;
	for (int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		Xmax=max(Xmax,x);
		Xmin=min(Xmin,x);
		Ymax=max(Ymax,y);
		Ymin=min(Ymin,y);
	}
	ll dx=llabs(Xmax-Xmin);
	dx*=dx;
	ll dy=llabs(Ymax-Ymin);
	dy*=dy;
	cout<<max(dx,dy)<<"\n";
}
