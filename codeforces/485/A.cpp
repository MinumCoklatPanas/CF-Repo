#include <bits/stdc++.h>
using namespace std;

bool sudah[100010];

int main()
{
	int a,m;
	cin>>a>>m;
	a%=m;
	sudah[a]=1;
	while (a!=0)
	{
		a=(a+(a%m))%m;
		if (sudah[a])
		{
			cout<<"No\n";
			return 0;
		}
		sudah[a]=1;
	}
	cout<<"Yes\n";
}
