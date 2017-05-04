#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main ()
{
	char tab[200010];
	int i,c,n;
	cin>>n;
	for (i=1;i<=n;i++)
	 tab[i]='a';
	for (i=3;i<=n;i++)
	{
		if (tab[i-2]=='a')
		 tab[i]='b';
		if (tab[i-2]=='b')
		 tab[i]='a';
	}
	for (i=1;i<=n;i++)
	{
		if (i==n) 
		 cout<<tab[i]<<"\n";
		else
		 cout<<tab[i];
	}
}
