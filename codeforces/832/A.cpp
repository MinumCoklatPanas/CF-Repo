#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long i,j,k,n;
	cin>>n>>k;
	if (n==k)
	{
		cout<<"YES\n";
		return 0;
	}
	else
	 {
	 	long long bagi=(n/k);
	 	if (bagi%2==1)
	 	{
	 		cout<<"YES\n";
	 		return 0;
		 }
		else
		 {
		 	cout<<"NO\n";
		 	return 0;
		 }
	 }
}
