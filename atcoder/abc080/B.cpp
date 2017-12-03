#include <bits/stdc++.h>
using namespace std;

int digsum(int x)
{
	int res=0;
	while (x>0)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	cout<<(n%digsum(n)==0 ? "Yes" : "No")<<"\n";
}