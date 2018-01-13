#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int mn=1e9;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if (k%a!=0) continue;
		mn=min(mn,k/a);
	}
	cout<<mn<<"\n";
}
