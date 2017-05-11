#include <iostream>
using namespace std;

int ceil(int x,int y)
{
	float f=(float)x/y;
	int e=(int)f;
	if (e==f)
	 return e;
	else
	 return e+1;
}

int main()
{
	//int n,t,k,d;
	//cin>>n>>t>>k>>d;
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	if ((t+d)<(ceil(n,k)*t))
	 cout<<"YES\n";
	else
	 cout<<"NO\n";
	 return 0;
}
