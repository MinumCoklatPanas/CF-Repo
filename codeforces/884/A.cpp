#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t;
	cin>>n>>t;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		int sisa=86400-a;
		t-=sisa;
		if (t<=0)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<n<<"\n";
}
