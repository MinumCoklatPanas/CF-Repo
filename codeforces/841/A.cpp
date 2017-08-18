#include <iostream>
#include <string>
using namespace std;

int i,j,k,n,huruf[30];

int main()
{
	
	cin>>n>>k;
	char ch;
	for (i=1;i<=n;i++)
	{
		cin>>ch;
		int asc=(int)ch;
		asc-=96;
		huruf[asc]++;
	}
	for (i=1;i<=26;i++)
	{
		if (huruf[i]>k)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}

