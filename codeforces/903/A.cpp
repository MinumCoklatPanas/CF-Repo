#include <bits\stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while (n--)
	{
		int k;
		cin>>k;
		bool ada=false;
		for (int i=0;i<=k;i++)
		{
			if (k<i*3) break;
			if ((k-(i*3))%7==0)
			{
				cout<<"YES\n";
//				cout<<i<<" i\n";
				ada=true;
				break;
			}
		}
		if (!ada)
		 cout<<"NO\n";
	}
}
