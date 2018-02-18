#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	cin>>n>>a;
	if (a>=n)
	 cout<<"Yes\n";
	else
	 {
	 	for (int i=0;i<=a;i++)
	 	{
	 		int sisa=n-i;
	 		if (sisa%500==0)
	 		{
	 			cout<<"Yes\n";
	 			return 0;
			 }
		}
		cout<<"No\n";
	 }
}
