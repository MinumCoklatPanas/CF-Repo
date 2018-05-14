#include <bits/stdc++.h>
using namespace std;

bool ada[1010];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		ada[a]=1;
	}
	for (int i=1;i<=998;i++)
	{
		if (ada[i] && ada[i+1] && ada[i+2])
		{
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
}
