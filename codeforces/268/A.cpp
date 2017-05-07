#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,n,count=0;
	pair <int,int> tab[35];
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i].first>>tab[i].second;
	for (i=1;i<n;i++)
	 for (j=i+1;j<=n;j++)
	 {
	 	if (tab[i].first==tab[j].second)
	 	 count++;
	 	if (tab[i].second==tab[j].first)
	 	 count++;
	 }
	cout<<count<<"\n";
}
