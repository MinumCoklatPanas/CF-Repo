#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	if (n<2 || m<2)
	 cout<<0<<"\n";
	else
	 {
	 	cout<<(n-1)*(m-1)<<"\n";
	 }
}