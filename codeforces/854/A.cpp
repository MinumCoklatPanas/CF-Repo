#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
	if (y==0)
	 return x;
	return gcd(y,x%y);
}

int main()
{
	int n;
	cin>>n;
	int i,j;
	for (i=n/2;i>=1;i--)
	{
		int satunya=n-i;
		if (gcd(i,satunya)==1)
		{
			cout<<i<<" "<<satunya<<"\n";
			return 0;
		}
	}
}
