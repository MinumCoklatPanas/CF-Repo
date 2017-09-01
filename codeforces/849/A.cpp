#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n,tab[110];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	if (n%2==0)
	{
		cout<<"No\n";
		return 0;
	}
	if (tab[1]%2==0 || tab[n]%2==0)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	return 0;
}
