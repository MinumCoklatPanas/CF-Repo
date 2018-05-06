#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if (n<10)
	{
		cout<<n-k<<"\n";
		return 0;
	}
	while (k--)
	{
		if (n%10!=0)
		 --n;
		else
		 n/=10;
	}
	cout<<n<<"\n";
}
