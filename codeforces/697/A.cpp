#include <iostream>
using namespace std;

int main()
{
	int t,s,x;
	cin>>t>>s>>x;
	//cout<<(x-t)%s<<"\n";
	if (((((x-t)%s==0)||((x-t-1)%s==0))&&(x>=s+t))||(x==t))
	 cout<<"YES\n";
	else
	 cout<<"NO\n";
}
