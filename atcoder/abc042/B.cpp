#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n;
	string tab[110];
	cin>>n>>k;
	for (i=1;i<=n;i++)
	{
		cin>>tab[i];
	}
	sort(tab+1,tab+n+1);
	string ans;
	ans="";
	for (i=1;i<=n;i++)
	 ans+=tab[i];
	cout<<ans<<"\n";
}