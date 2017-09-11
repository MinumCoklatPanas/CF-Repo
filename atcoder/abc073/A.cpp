#include <bits/stdc++.h>
using namespace std;

bool ada(int x)
{
	while (x>0)
	{
		if (x%10==9)
		 return true;
		x/=10;
	}
	return false;
}

int main()
{
	int x;
	cin>>x;
	//cout<<x<<"\n";
	cout<<(ada(x) ? "Yes" : "No")<<"\n";
}