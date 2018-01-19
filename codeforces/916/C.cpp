#include <bits/stdc++.h>
using namespace std;

bool prime(int x)
{
	if (x==1) return false;
	int akar=(int)sqrt(x);
	for (int i=2;i<=akar;i++)
	 if (x%i==0) return false;
	return true;
}

int smallestprime(int n)
{
//	cout<<n<<"\n";
	while (!prime(n))
	 ++n;
	return n;
}

int main()
{
	int n,m;
	cin>>n>>m;
//	cout<<n<<" "<<m<<"\n";
	int sp=smallestprime(n-1);
	cout<<sp<<" "<<sp<<"\n";
	for (int i=1;i<n-1;i++)
	{
		cout<<i<<" "<<i+1<<" "<<1<<"\n";
	}
	cout<<n-1<<" "<<n<<" "<<sp-n+2<<"\n";
	int count=3;
	int now=1;
	for (int i=1;i<=m-n+1;i++)
	{
		cout<<now<<" "<<count++<<" "<<1000000000<<"\n";
		if (count>n)
		{
			now++;
			count=now+2;
		}
	}
}
