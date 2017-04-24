#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int n,k,i;
	pair <int,int> tab[110];
	cin>>n>>k;
	bool b = false;
	int sum=0;
	int hasil[110];
	for (i=1;i<=n;i++)
	{
		cin>>tab[i].first;
		tab[i].second=i;
	}
	sort(tab+1,tab+n+1);
	for (i=1;i<=n;i++)
	{
		if (tab[i].first<=k)
		{
			k-=tab[i].first;
			sum++;
			hasil[sum]=tab[i].second;
		}
		else
		 break;
	}
	cout<<sum<<"\n";
	for (i=1;i<=sum;i++)
	{
		if (i==sum)
		 cout<<hasil[i]<<"\n";
		else
		 cout<<hasil[i]<<" ";
	}
}
