#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
//	freopen("input.txt","r",stdin);
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
	ll fpb=__gcd(x,y);
	x/=fpb;
	y/=fpb;
//	cout<<a/x<<" "<<y/b<<"\n";
	cout<<min(a/x,b/y)<<"\n";
}