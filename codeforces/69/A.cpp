#include <iostream>
using namespace std;

int main()
{
	int i,j,k,n,sumX,sumY,sumZ;
	cin>>n;
	sumX=0;
	sumY=0;
	sumZ=0;
	int a,b,c;
	for (i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		sumX+=a;
		sumY+=b;
		sumZ+=c;
	}
	if (!sumX && !sumY && !sumZ)
	 cout<<"YES\n";
	else
	 cout<<"NO\n";
}
