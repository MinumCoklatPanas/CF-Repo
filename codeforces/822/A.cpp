#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
	ll i,j,k,a,b;
	cin>>a>>b;
	k=min(a,b);
	ll ans=1;
	for (i=1;i<=k;i++)
	 ans*=i;
	cout<<ans<<"\n";
}
