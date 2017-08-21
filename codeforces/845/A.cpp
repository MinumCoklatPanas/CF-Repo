#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n,tab[220];
	cin>>n;
	int m=2*n;
	for (i=1;i<=m;i++)
	 cin>>tab[i];
	sort(tab+1,tab+m+1);
	for (i=(m/2)+1;i<=m;i++)
	 for (j=1;j<=m/2;j++)
	 {
	 	if (tab[i]<=tab[j])
	 	{
	 		cout<<"NO\n";
	 		return 0;
		}
	 }
	 cout<<"YES\n";
}
