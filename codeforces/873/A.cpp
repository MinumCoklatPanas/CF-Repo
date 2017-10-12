#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,x;
	cin>>n>>k>>x;
	int sum=0;
	while (n--)
	{
	//	cout<<n<<" n\n";
		int a;
		cin>>a;
		if (n<k)
		 sum+=x;
		else
		 sum+=a;
	//	cout<<sum<<"\n";
	}
	cout<<sum<<"\n";
}