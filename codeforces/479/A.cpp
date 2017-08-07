#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a,b,c;
	//scanf("%d %d %d",&a,&b,&c);
	cin>>a>>b>>c;
	int ans=-1;
	int x=(a+b)*c;
	ans=max(ans,x);
	x=a*(b+c);
	ans=max(ans,x);
	x=a+b+c;
	ans=max(ans,x);
	x=a*b*c;
	ans=max(ans,x);
	cout<<ans<<"\n";
}
