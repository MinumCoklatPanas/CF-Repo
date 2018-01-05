#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a,b;
	cin>>a>>b;
	long long x,y,z;
	cin>>x>>y>>z;
	long long butuhy=2*x+y;
	long long butuhx=3*z+y;
	long long needy=butuhy-a;
	long long needb=butuhx-b;
	butuhy=max(0ll,needy);
	butuhx=max(0ll,needb);
	cout<<butuhy+butuhx<<"\n";
}
